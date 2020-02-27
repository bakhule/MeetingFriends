#include "TXLib.h"

//----------------------------------------------------------------------------

void JumpMan     (int x, int y, int sizeX, int sizeY, double jump,
                  COLORREF color, COLORREF bkColor, int jumps, int delay);

void MoveMan     (int fromX, int fromY, int toX, int toY,
                  int sizeX, int sizeY, COLORREF color, COLORREF bkColor,
                  int time, int steps);

void DrawMan     (int x, int y, int sizeX, int sizeY, COLORREF color,
                  double hand = 0, double legs = 0, double head = 0, double twist = 0);

void DrawWoman   (int fromX, int fromY, int toX, int toY,
                  int sizeX, int sizeY, COLORREF color, COLORREF bkColor,
                  int time, int steps);

void AppearText  (int x, int y, const char* text, COLORREF from, COLORREF to,
                  int time, int steps);
void AppearHello  (int x, int y, const char* text, COLORREF from, COLORREF to,
                  int time, int steps);

void DrawHello   (int x, int y, const char* text, int size, COLORREF color);

void UnwindFlag  (int x, int y, int fromSizeX, int toSizeX, int sizeY,
                  COLORREF color, COLORREF bkColor, int time, int steps);

void DrawFlag    (int x, int y, int sizeX, int sizeY, COLORREF color, COLORREF bkColor);

void DrawFrame   (int sizeX, int sizeY, int size, COLORREF color);

//----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600);
    txTextCursor (false);

    DrawFrame (800, 600, 10, TX_WHITE);

    txSelectFont ("Times New Roman", 30);
    txSetTextAlign (TA_CENTER);

    AppearText  (400, 480, "MEETING FRIENDS", TX_BLACK, TX_PINK, 5000, 100);
    MoveMan     (20, 500, 380, 150, 50, 80,  TX_WHITE, TX_BLACK,     3000, 100);
    DrawWoman   (700, 500, 420, 150, 50, 80,     TX_WHITE, TX_BLACK,     3000, 100);
    JumpMan     (700, 150, 50, 80, 0.25,     TX_PINK, TX_BLACK,       10, 100);
    UnwindFlag  (450, 150, 0, 40, 60,        TX_WHITE, TX_BLACK,      500, 100);
    AppearHello (650, 100, "Hello", TX_BLACK, TX_PINK, 5000, 100);
    return 0;
    }
void drawFon(int width, int height, int red, int green, int blue)
    {
        txClear();
        txSetColor (RGB (red, green, blue), 4);
        txSetFillColor (TX_BLUE);
        txRectangle (0, 0, width, height);

    }

//----------------------------------------------------------------------------

void JumpMan (int x, int y, int sizeX, int sizeY, double jump,
              COLORREF color, COLORREF bkColor, int jumps, int delay)
    {
    DrawMan (x, y, sizeX, sizeY, TX_BLACK, 0, 0, 0, 0);

    txBegin();

    int i = 0;
    while (i < jumps)
        {
        DrawMan (x, y - (int)(i%2 * jump*10), sizeX, sizeY, color,
                (i%2-0.5) * jump/3, 0, (i%2-0.5) * -jump/3, 0);

        txSleep (delay);

        DrawMan (x, y - (int)(i%2 * jump*10), sizeX, sizeY, bkColor,
                (i%2-0.5) * jump/3, 0, (i%2-0.5) * -jump/3, 0);
        i++;
        }

    DrawMan (x, y - (int)(jumps%2 * jump*10), sizeX, sizeY, color,
            (jumps%2-0.5) * jump/3, 0, (jumps%2-0.5) * -jump/3, 0);

    txEnd();
    }

//----------------------------------------------------------------------------

void MoveMan (int fromX, int fromY, int toX, int toY,
              int sizeX, int sizeY, COLORREF color, COLORREF bkColor,
              int time, int steps)
    {
    txBegin();

    int i = 0;
    while (i <= steps)
        {
        int x = fromX + (toX - fromX) * i/steps,
            y = fromY + (toY - fromY) * i/steps;

        DrawMan (x, y - i%6, sizeX, sizeY, color,   i%3*0.02, i%3*-0.1, i%3*0.1, 0);

        txSleep (time / steps);

        DrawMan (x, y - i%6, sizeX, sizeY, bkColor, i%3*0.02, i%3*-0.1, i%3*0.1, 0);
        i++;
        }

    DrawMan (toX, toY, sizeX, sizeY, color, 0, 0, 0);

    txEnd();
    }

//----------------------------------------------------------------------------

void DrawWoman (int fromX, int fromY, int toX, int toY,
              int sizeX, int sizeY, COLORREF color, COLORREF bkColor,
              int time, int steps)
    {
    txBegin();

    int i = 0;
    while (i <= steps)
        {
        int x = fromX + (toX - fromX) * i/steps,
            y = fromY + (toY - fromY) * i/steps;

        DrawMan (x, y - i%6, sizeX, sizeY, color,   i%3*0.02, i%3*-0.1, i%3*0.1, 0);

        txSleep (time / steps);

        DrawMan (x, y - i%6, sizeX, sizeY, bkColor, i%3*0.02, i%3*-0.1, i%3*0.1, 0);
        i++;
        }

    DrawMan (toX, toY, sizeX, sizeY, color, 0, 0, 0);

    txEnd();
    }

//----------------------------------------------------------------------------

void UnwindFlag (int x, int y, int fromSizeX, int toSizeX, int sizeY,
                 COLORREF color, COLORREF bkColor, int time, int steps)
    {
    txBegin();

    int i = 0;
    while (i <= steps)
        {
        int sizeX = fromSizeX + (toSizeX - fromSizeX) * i/steps;

        DrawFlag (x, y, sizeX, sizeY, color,   bkColor);

        txSleep  (time / steps);

        DrawFlag (x, y, sizeX, sizeY, bkColor, bkColor);
        i++;
        }

    DrawFlag (x, y, toSizeX, sizeY, color, bkColor);

    txEnd();
    }

//----------------------------------------------------------------------------

void DrawMan (int x, int y, int sizeX, int sizeY, COLORREF color,
              double hand, double legs, double head, double twist)
    {
    txSetColor     (color);
    txSetFillColor (color);

    txLine (x + twist*sizeX, y - 0.35*sizeY, x, y - 0.7*sizeY);

    txLine (x + twist*sizeX, y - 0.35*sizeY, x - (0.5 + legs) * sizeX, y);
    txLine (x + twist*sizeX, y - 0.35*sizeY, x + (0.5 + legs) * sizeX, y);

    txLine (x, y - 0.65*sizeY, x - sizeX/2,   y - 0.4*sizeY);
    txLine (x, y - 0.65*sizeY, x + sizeX/1.2, y - (0.7 + hand) * sizeY);

    txCircle (x, y - sizeY + (0.3 + head) * sizeX, 0.3*sizeX);
    }

//----------------------------------------------------------------------------

void AppearText (int x, int y, const char* text, COLORREF from, COLORREF to,
                 int time, int steps)
    {
     int r0 = txExtractColor (from, TX_RED),   r1 = txExtractColor (to, TX_RED),
         g0 = txExtractColor (from, TX_GREEN), g1 = txExtractColor (to, TX_GREEN),
         b0 = txExtractColor (from, TX_BLUE),  b1 = txExtractColor (to, TX_BLUE);

    for (int i = 0; i <= steps; i++)
        {
        int r = r0 + (r1 - r0) * i/steps,
            g = g0 + (g1 - g0) * i/steps,
            b = b0 + (b1 - b0) * i/steps;

        txSetColor (RGB (r, g, b));
        txTextOut (x, y, text);

        Sleep (time / steps);
        }
    }

//----------------------------------------------------------------------------

void DrawFlag (int x, int y, int sizeX, int sizeY, COLORREF color, COLORREF bkColor)
    {
    txSetColor     (color);
    txSetFillColor (bkColor);

    txLine (x, y, x, y - sizeY);
    txRectangle (x, y - sizeY/2, x + sizeX, y - sizeY);

    txSelectFont ("Times New Roman", sizeX/2 + 1);
    txTextOut (x + sizeX/2, y - sizeY*7/8, "HI!");
    }

//----------------------------------------------------------------------------

void DrawHello (int x, int y, const char* text, int size, COLORREF color)
    {
    txSetColor (color);

    txSelectFont ("Times New Roman", size);
    txSetTextAlign (TA_CENTER);

    txTextOut (x, y, text);
    }

void AppearHello (int x, int y, const char* text, COLORREF from, COLORREF to,
                 int time, int steps)
    {
     int r0 = txExtractColor (from, TX_RED),   r1 = txExtractColor (to, TX_RED),
         g0 = txExtractColor (from, TX_GREEN), g1 = txExtractColor (to, TX_GREEN),
         b0 = txExtractColor (from, TX_BLUE),  b1 = txExtractColor (to, TX_BLUE);

    for (int i = 0; i <= steps; i++)
        {
        int r = r0 + (r1 - r0) * i/steps,
            g = g0 + (g1 - g0) * i/steps,
            b = b0 + (b1 - b0) * i/steps;

        txSetColor (RGB (r, g, b));
        txTextOut (x, y, text);

        Sleep (time / steps);
        }
    }

//----------------------------------------------------------------------------

void DrawFrame (int sizeX, int sizeY, int size, COLORREF color)
    {
    txSetColor (color);
    txSetFillColor (TX_TRANSPARENT);

    txRectangle (size, size, sizeX-size, sizeY-size);
    }
