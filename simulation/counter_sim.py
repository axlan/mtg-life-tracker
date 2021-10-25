import pygame

successes, failures = pygame.init()
print("Initializing pygame: {0} successes and {1} failures.".format(successes, failures))

screen = pygame.display.set_mode((720, 480))
clock = pygame.time.Clock()
FPS = 60

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)


font = pygame.font.Font(None, 36)

class Display(pygame.sprite.Sprite):
    def __init__(self, x, y):
        super().__init__()
        self.image = None
        self.rect = pygame.Rect(x, y, 0, 0)
        self.value = None
        self.update_value(0)

    def update_value(self, val):
        if val != self.value:
            self.value = val
            self.image = font.render(str(val), 1, (255, 255, 255))
            self.rect.w = self.image.get_rect().w
            self.rect.h = self.image.get_rect().h

display = Display(100, 100)
running = True
while running:
    dt = clock.tick(FPS) / 1000  # Returns milliseconds between each call to 'tick'. The convert time to seconds.
    screen.fill(BLACK)  # Fill the screen with background color.

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_w:
                display.update_value(display.value + 1)
            elif event.key == pygame.K_s:
                display.update_value(display.value - 1)

    screen.blit(display.image, display.rect)
    pygame.display.update()  # Or pygame.display.flip()

print("Exited the game loop. Game will quit...")
quit()  # Not actually necessary since the script will exit anyway.
