// ml:run = time -p $bin
#include <iostream>
#include <vector>
#include <string>
#include "691.hh"

int main()
{
    std::vector<std::string> stickers{
        "point","square","love","show","ran","certain","soil","period","say","human","duck","meet","speed","lie","differ","depend","thank","floor","sail","father","spring","field","music","too","interest","suit","new","finish","electric","parent","song","read","who","effect","fall","spoke","on","short","center","organ","plain","straight","near","so","she","science","quick","position","problem","history",
    };
    std::cout << Solution{}.minStickers(
        stickers,
        "chargeresult"
    ) << "\n";
}

