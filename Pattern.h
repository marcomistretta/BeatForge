//
// Created by misterm on 11/05/19.
//

#ifndef DRUMMACHINE_PATTERN_H
#define DRUMMACHINE_PATTERN_H

#include <string>
#include <vector>

struct Percussions{
    std::string name;
    std::string filename;
    std::vector<bool> groove;
};


class Pattern {
public:
    const std::vector<Percussions> &getDrumset() const {
        return drumset;
    }

    void setDrumset(const std::vector<Percussions> &drumset) {
        Pattern::drumset = drumset;
    }

    int getNumberOfBars() const {
        return numberOfBars;
    }

    void setNumberOfBars(int numberOfBars) {
        Pattern::numberOfBars = numberOfBars;
    }

    const std::string &getName() const {
        return drums.name;
    }

    void setName(const std::string &name) {
        Pattern::drums.name = name;
    }

    const std::string &getFilename() const {
        return drums.filename;
    }

    void setFilename(const std::string &filename) {
        Pattern::drums.filename = filename;
    }

    const std::vector<bool> &getGroove() const {
        return drums.groove;
    }

    void setGroove(const std::vector<bool> &groove) {
        Pattern::drums.groove = groove;
    }

    void savePattern();


    void loadPattern();


private:
    std::vector<Percussions> drumset;
    int numberOfBars;
    const static int maxPercussions {10};
    Percussions drums;
};


#endif //DRUMMACHINE_PATTERN_H
