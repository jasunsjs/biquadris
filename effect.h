#ifndef EFFECT_H
#define EFFECT_H

class Effect {
  public:
    virtual ~Effect() = default;
    virtual void apply(Board& board) = 0;
};

#endif
