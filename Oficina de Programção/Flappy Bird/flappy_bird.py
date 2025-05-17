import pygame
import random
import sys

# Inicializa o pygame
pygame.init()

# Configurações da tela
WIDTH = 400
HEIGHT = 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('Flappy Cartola')

# Cores e fonte
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
font = pygame.font.SysFont('Arial', 30, bold=True)

# Carregar imagens
background_img = pygame.image.load('background.png').convert()
background_img = pygame.transform.scale(background_img, (WIDTH, HEIGHT))

cartola_img = pygame.image.load('cartola.png').convert_alpha()
cartola_img = pygame.transform.scale(cartola_img, (50, 50))

pipe_img = pygame.image.load('pipe.png').convert_alpha()
pipe_img = pygame.transform.scale(pipe_img, (60, HEIGHT))
pipe_flipped_img = pygame.transform.flip(pipe_img, False, True)

base_img = pygame.image.load('base.png').convert()
base_img = pygame.transform.scale(base_img, (WIDTH, 100))
base_y = HEIGHT - 100

# Configurações do jogo
gravity = 0.25
bird_movement = 0
game_active = True
score = 0
high_score = 0
passed_pipes = set()

# Ajuste para canos mais fechados (reduzindo o gap)
pipe_gap = 1  # Reduzi de 180 para 120 (quanto menor, mais difícil)

# Máscaras para colisão precisa
cartola_mask = pygame.mask.from_surface(cartola_img)
pipe_mask = pygame.mask.from_surface(pipe_img)
pipe_flipped_mask = pygame.mask.from_surface(pipe_flipped_img)

# Classe do personagem
class Cartola:
    def __init__(self):
        self.x = 100
        self.y = 250
        self.width = 50
        self.height = 50
    
    @property
    def rect(self):
        return pygame.Rect(self.x, self.y, self.width, self.height)

cartola = Cartola()

# Canos
pipe_width = 60
pipe_list = []
SPAWNPIPE = pygame.USEREVENT
pygame.time.set_timer(SPAWNPIPE, 1500)

clock = pygame.time.Clock()

def create_pipe():
    pipe_height = random.randint(200, 400)  # Ajuste para compensar o gap menor
    bottom_pipe = pipe_img.get_rect(midtop=(WIDTH, pipe_height))
    top_pipe = pipe_flipped_img.get_rect(midbottom=(WIDTH, pipe_height - pipe_gap))
    return bottom_pipe, top_pipe, WIDTH

def move_pipes(pipes):
    for pipe in pipes:
        pipe['x'] -= 3
        pipe['bottom_pipe'].x = pipe['x']
        pipe['top_pipe'].x = pipe['x']
    return [pipe for pipe in pipes if pipe['x'] > -pipe_width]

def draw_pipes(pipes):
    for pipe in pipes:
        screen.blit(pipe_img, pipe['bottom_pipe'])
        screen.blit(pipe_flipped_img, pipe['top_pipe'])

def check_collision(pipes):
    for pipe in pipes:
        # Cano inferior
        offset = (pipe['bottom_pipe'].x - cartola.x, pipe['bottom_pipe'].top - cartola.y)
        if cartola_mask.overlap(pipe_mask, offset):
            return False
        
        # Cano superior
        offset = (pipe['top_pipe'].x - cartola.x, pipe['top_pipe'].top - cartola.y)
        if cartola_mask.overlap(pipe_flipped_mask, offset):
            return False
    
    if cartola.rect.top <= 0 or cartola.rect.bottom >= HEIGHT - 100:
        return False
    return True

def update_score(pipes, score, passed_pipes):
    for pipe in pipes:
        if pipe['id'] not in passed_pipes and pipe['x'] + pipe_width < cartola.x:
            passed_pipes.add(pipe['id'])
            score += 1
    return score, passed_pipes

def display_score(score, high_score, game_active):
    score_surface = font.render(f'Score: {int(score)}', True, WHITE)
    score_rect = score_surface.get_rect(center=(WIDTH // 2, 50))
    screen.blit(score_surface, score_rect)
    
    if not game_active:
        high_score_surface = font.render(f'High Score: {int(high_score)}', True, WHITE)
        high_score_rect = high_score_surface.get_rect(center=(WIDTH // 2, 100))
        screen.blit(high_score_surface, high_score_rect)

        restart_surface = font.render('Press SPACE to restart', True, WHITE)
        restart_rect = restart_surface.get_rect(center=(WIDTH // 2, 150))
        screen.blit(restart_surface, restart_rect)

def draw_cartola():
    screen.blit(cartola_img, (cartola.x, cartola.y))

# Loop principal
pipe_id_counter = 0
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and game_active:
                bird_movement = 0
                bird_movement -= 7
            
            if event.key == pygame.K_SPACE and not game_active:
                game_active = True
                pipe_list.clear()
                passed_pipes.clear()
                cartola = Cartola()
                bird_movement = 0
                score = 0
                pipe_id_counter = 0
        
        if event.type == SPAWNPIPE and game_active:
            bottom_pipe, top_pipe, x_pos = create_pipe()
            pipe_list.append({
                'id': pipe_id_counter,
                'x': x_pos,
                'bottom_pipe': bottom_pipe,
                'top_pipe': top_pipe
            })
            pipe_id_counter += 1

    # Fundo
    screen.blit(background_img, (0, 0))

    if game_active:
        bird_movement += gravity
        cartola.y += bird_movement
        draw_cartola()

        pipe_list = move_pipes(pipe_list)
        draw_pipes(pipe_list)

        game_active = check_collision(pipe_list)
        score, passed_pipes = update_score(pipe_list, score, passed_pipes)
    else:
        high_score = max(score, high_score)
        draw_cartola()
    
    screen.blit(base_img, (0, base_y))
    display_score(score, high_score, game_active)

    pygame.display.update()
    clock.tick(60)