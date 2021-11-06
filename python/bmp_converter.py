import struct
import sys
import math

def ReadBmp(file_path):
    with open(file_path, 'rb') as fd:

        # Skip to size in header
        fd.seek(18, 0)
        w = struct.unpack('I', fd.read(4))[0]
        h = struct.unpack('I', fd.read(4))[0]
     
        lineSize =  int(w / 8) + int(w / 8) % 4
        fileSize = lineSize * h

        # skip the header
        # skip the palette
        fd.seek(54 + 8, 0)
        # read data
        data = fd.read(fileSize)
        img = []
        # decode bits
        for j in range(h):
            line = []
            for i in range(w):
                byte_ctr = int(i / 8)
                data_byte = data[j * lineSize + byte_ctr]
                mask = 0x80 >> i % 8
                line.append(1 if data_byte & mask else 0)
            img.insert(0, line)
    return img

def PrintPretty(data):
    for row in data:
        print(' '.join(['0' if i else '*' for i in row]))

def PrintCArray(name, data, invert=False):
    width = len(data[0])
    height = len(data)
    print(f'constexpr uint16_t {name.upper()}_WIDTH = {width};')
    print(f'constexpr uint16_t {name.upper()}_HEIGHT = {height};')
    bytes_per_line = math.ceil(width / 8)
    array_str = f'static const unsigned char PROGMEM {name}_bmp[] = {{\n'
    for line in data:
        i = 0
        array_str += "  "
        for _ in range(bytes_per_line):
            byte_val = 0
            for k in range(8):
                if i >= width:
                    break
                if (invert and not line[i]) or (not invert and line[i]):
                    byte_val += 1 << (7 - k)
                i += 1
            array_str += f'0b{byte_val:08b},'
        array_str += '\n'
    array_str = array_str[:-2] + '};'
    print(array_str)

def scale(data, multiplier):
    scaled = []
    for line in data:
        line = sum([[i] * multiplier for i in line], [])
        scaled += [line] * multiplier
    return scaled
        

def Main(file_path):
    data = ReadBmp(file_path)
    PrintPretty(data)
    data = scale(data, 1)
    PrintCArray("squirrel", data)


if __name__ == '__main__':
    Main(sys.argv[1])
