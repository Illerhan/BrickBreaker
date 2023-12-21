// Component.h
#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
public:
    virtual ~Component() {}
    virtual void Update() = 0;
    // Add more virtual functions as needed
};

#endif // COMPONENT_H
