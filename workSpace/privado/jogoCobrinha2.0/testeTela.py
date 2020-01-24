import curses
import locale
import time
import random
locale.setlocale(locale.LC_ALL, '')
encoding = locale.getpreferredencoding()

def sorteia_maca(screen):
    pos = random.randrange(0, curses.COLS), random.randrange(0, curses.LINES)
    screen.addstr(pos[1], pos[0], b"@")

def main(screen):
    curses.curs_set(0)
    screen.nodelay(True)
    y, x = 20, 20
    direction = (1, 0)
    comprimento = 5
    corpo = []
    sorteia_maca(screen)
    pontuacao = 0
    while True:
        key = screen.getch()
        if key == curses.KEY_LEFT:
            direction = (-1, 0)
        elif key == curses.KEY_RIGHT:
            direction = (1, 0)
        elif key == curses.KEY_DOWN:
            direction = (0, 1)
        elif key == curses.KEY_UP:
            direction = (0, -1)
        elif key in (0x1b, ord("q")): # <ESC>
            break
        x += direction[0]
        y += direction[1]

        corpo.insert(0, (x, y))
        if len(corpo) > comprimento:
            final = corpo.pop()
            screen.addstr(final[1], final[0], b" ")

        cabeca_em = screen.instr(y, x, 1)
        if cabeca_em == b"@":
            pontuacao += 5
            comprimento += 5
            sorteia_maca(screen)

        elif cabeca_em != b" " or x >= curses.COLS or y > curses.LINES or x < 0 or y < 0:
            screen.addstr(10, 15, "Você morreu! Pontos: {}".format(pontuacao).encode(encoding))
            screen.refresh()
            time.sleep(3)
            break

        screen.addstr(y, x, b"*")
        screen.refresh()
        time.sleep(0.1)

curses.wrapper(main)