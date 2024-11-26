#ifndef EFFECT_H
#define EFFECT_H

class Effect {
public:
    virtual void apply() = 0;
    virtual ~Effect() = default;
};

#endif
