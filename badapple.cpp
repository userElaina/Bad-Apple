#include "cmdline/cmdline.h"
#include "badapple.hpp"

int main(int argc, char** argv) {
    cmdline::parser a;
    a.set_program_name("badapple");
    a.add<std::string>("input", 'i', "video file", false, "./badapple.mp4");
    a.add<std::string>("output", 'o', "[preloaded mode] output file", false, "");
    a.add<std::string>("audio", 'a', "audio file", false, "");
    a.add<std::string>("map", 'm', "font data file", false, "");
    a.add<std::string>("scale", 's', "width:height", false, "76:54");
    a.add<double>("rate", 'r', "set frame rate", false, 10.0);
    a.add("contrast-enhancement", '\0', "contrast enhancement");
    a.add("play-audio", '\0', "play audio with ffplay");
    a.parse_check(argc, argv);

    int x, y;
    sscanf(a.get<std::string>("scale").c_str(), "%d:%d", &x, &y);
    play(a.get<std::string>("input"), a.get<std::string>("output"), a.get<std::string>("audio"), a.get<std::string>("map"), x, y, a.get<double>("rate"), a.exist("contrast-enhancement"), a.exist("play-audio"));
}
