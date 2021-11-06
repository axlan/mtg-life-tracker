import pygame
from enum import Enum

successes, failures = pygame.init()
print("Initializing pygame: {0} successes and {1} failures.".format(successes, failures))

screen = pygame.display.set_mode((720, 480))
clock = pygame.time.Clock()
FPS = 60

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)


font = pygame.font.Font(None, 36)

class Display(pygame.sprite.Sprite):
    class State(Enum):
        ON=0,
        OFF=1,
        BLINK=2

    def __init__(self, x, y):
        super().__init__()
        self.rect = pygame.Rect(x, y, 0, 0)
        self.value = 0
        self.state = self.State.ON
        self.time = 0
        self.dp = False

    def get_image(self, dt):
        self.time += dt
        val = str(self.value)
        if self.dp:
            val += '.'
        if self.state == self.State.ON or (self.state == self.State.BLINK and int(self.time * 2) % 2 == 0):
            image = font.render(val, 1, (255, 255, 255))
            self.rect.w = image.get_rect().w
            self.rect.h = image.get_rect().h
            return image
        return None

class Tracker:

    def __init__(self):
        self.selected = 0
        self.life_total = 0
        self.displays = [ Display(500 - 100 * i, 100) for i in range(1,5) ]
        self.select(0)

    def select(self, idx):
        self.displays[self.selected].dp = False
        self.selected = idx
        self.displays[idx].dp = True

    def update_value(self):
        for i, display in enumerate(self.displays):
            display.value = int(self.life_total / (10**i)) % 10

    def run(self):

        running = True
        while running:
            dt = clock.tick(FPS) / 1000  # Returns milliseconds between each call to 'tick'. The convert time to seconds.
            screen.fill(BLACK)  # Fill the screen with background color.

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.KEYUP:
                    if event.key == pygame.K_w:
                        if self.life_total + 10 ** self.selected < 10000:
                            self.life_total += 10 ** self.selected
                    elif event.key == pygame.K_s:
                        if self.life_total >= 10 ** self.selected:
                            self.life_total -= 10 ** self.selected
                    elif event.key == pygame.K_d:
                        if self.selected > 0:
                            self.select(self.selected - 1)
                    elif event.key == pygame.K_a:
                        if self.selected < 3:
                            self.select(self.selected + 1)
                    self.update_value()

            for display in self.displays:
                shown_image = display.get_image(dt)
                if shown_image:
                    screen.blit(shown_image, display.rect)
            pygame.display.update()  # Or pygame.display.flip()

        print("Exited the game loop. Game will quit...")
        
tracker = Tracker()
tracker.run()
