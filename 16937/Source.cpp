#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Height, Width, StickerCount;
    std::cin >> Height >> Width >> StickerCount;

    struct FSticker
    {
        int Width;
        int Height;
        FSticker Rotate90() const { return {Height, Width}; }
        int Area() const { return Width * Height; }
    };

    std::vector<FSticker> Stickers(StickerCount);
    for (int i = 0; i < StickerCount; ++i)
    {
        std::cin >> Stickers[i].Height >> Stickers[i].Width;
    }

    const auto GetCombinedArea = [&](const FSticker& Sticker0, const FSticker& Sticker1)
    {
        const int SideBySideWidth = Sticker0.Width + Sticker1.Width;
        const int SideBySideHeight = std::max(Sticker0.Height, Sticker1.Height);
        const int AboveAndBelowWidth = std::max(Sticker0.Width, Sticker1.Width);
        const int AboveAndBelowHeight = Sticker0.Height + Sticker1.Height;

        if ((SideBySideWidth <= Width && SideBySideHeight <= Height)
            || (AboveAndBelowWidth <= Width && AboveAndBelowHeight <= Height))
        {
            return Sticker0.Area() + Sticker1.Area();
        }

        return 0;
    };

    int MaxArea = 0;
    for (int i = 0; i < StickerCount; ++i)
    {
        for (int j = i + 1; j < StickerCount; ++j)
        {
            MaxArea = std::max(MaxArea, GetCombinedArea(Stickers[i], Stickers[j]));
            MaxArea = std::max(MaxArea, GetCombinedArea(Stickers[i].Rotate90(), Stickers[j]));
            MaxArea = std::max(MaxArea, GetCombinedArea(Stickers[i], Stickers[j].Rotate90()));
            MaxArea = std::max(MaxArea, GetCombinedArea(Stickers[i].Rotate90(), Stickers[j].Rotate90()));
        }
    }

    std::cout << MaxArea;
}
