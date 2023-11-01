#include <stdio.h>
int main() {
  int pos_p1 = 0, pos_p2 = 0, pos_ballx = 40, pos_bally = 1, sizex = 80,
      sizey = 25, scorep1 = 0, scorep2 = 0, i = 1, ball_speedx = 2,
      ball_speedy = 1;
  while (i != 0) {
    for (int sy = 0; sy <= sizey; sy++) {
      for (int sx = 0; sx <= sizex + 1; sx++) {
        if (sx == sizex + 1) printf(" \n");
        else if (sy == pos_bally && sx == pos_ballx) printf("o");
        else if (sy == 0 && sx == 20) printf("%d", scorep1/10);
        else if (sy == 0 && sx == 21) printf("%d", scorep1 - (scorep1/10)*10);
        else if (sy == 0 && sx == 60) printf("%d", scorep2/10);
        else if (sy == 0 && sx == 61) printf("%d", scorep2 - (scorep2/10)*10);
        else if (sx == 39) printf("|");
        else if (sx == 41) printf("|");
        else if ((sy == pos_p1 || sy == pos_p1 + 1 || sy == pos_p1 + 2) &&
                 sx == 0) printf("]");
        else if ((sy == pos_p2 || sy == pos_p2 + 1 || sy == pos_p2 + 2) &&
                 sx == 80) printf("[");
        else
          printf(" ");
      }
    }
    char key_press;
    scanf("%c", &key_press);
    if (key_press == 'q')
      i = 0;
    if (key_press == 'a' || key_press == 'z' || key_press == 'm' ||
        key_press == 'k' || key_press == '\n') {
      if (key_press == 'a' && pos_p1 > 0)
        pos_p1--;
      if (key_press == 'z' && pos_p1 < sizey - 3)
        pos_p1++;
      if (key_press == 'k' && pos_p2 > 0)
        pos_p2--;
      if (key_press == 'm' && pos_p2 < sizey - 3)
        pos_p2++;
      if (key_press == '\n') {
        if (pos_ballx + ball_speedx == 82 || pos_ballx + ball_speedx == -2 ||
          (pos_ballx + ball_speedx == 80 &&
             (pos_bally == pos_p2 || pos_bally == pos_p2 + 1 ||
              pos_bally == pos_p2 + 2)) ||
            (pos_ballx + ball_speedx == 0 &&
             (pos_bally == pos_p1 || pos_bally == pos_p1 + 1 ||
              pos_bally == pos_p1 + 2))) {
              if (pos_ballx + ball_speedx == 82)
                  scorep1++;
              if (pos_ballx + ball_speedx == -2)
                  scorep2++;
              ball_speedx = ball_speedx * (-1);
          }
          if (pos_bally + 1 == 26 || pos_bally - 1 == -1)
              ball_speedy = ball_speedy * (-1);
          pos_ballx += ball_speedx;
          pos_bally += ball_speedy;
        }
    }
    if (scorep1 == 21 || scorep2 == 21)
      i = 0;
  }
  if (scorep1 == 21)
    printf("CONGRATULATIONS!!! PLAYER 2 (LEFT) WON!!!  :3\n");
  else
    printf("CONGRATULATIONS!!! PLAYER 1 (RIGHT) WON!!!  :3\n");
}
// comment