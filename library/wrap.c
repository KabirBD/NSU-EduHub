void printWrap(const char *text, int lineWidth)
{
    int length = strlen(text);
    int currentPosition = 0;

    while (currentPosition < length)
    {
        int wrapPosition = currentPosition + lineWidth;
        if (wrapPosition >= length)
        {
            wrapPosition = length;
        }
        else
        {
            while (wrapPosition > currentPosition && text[wrapPosition] != ' ')
            {
                wrapPosition--;
            }
            if (wrapPosition == currentPosition)
            {
                wrapPosition = currentPosition + lineWidth;
            }
        }

        for (int i = currentPosition; i < wrapPosition; i++)
        {
            putchar(text[i]);
        }
        putchar('\n');

        currentPosition = wrapPosition + 1;
    }
}
