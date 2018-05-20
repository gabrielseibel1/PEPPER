//
// Created by gabriel on 5/18/18.
//

#ifndef BINS_COMPONENT_H
#define BINS_COMPONENT_H

#include <ostream>
#include "table.h"
#include "MatrixManager.h"

#define UNUSED_NODE (-1)
#define MAX_NODES 4

enum Group {
    GROUP1 = 1, GROUP2 = 2
};

static const char *const I_SOURCE_STR = "I-SOURCE ";

static const char *const CAPACITOR_STR = "CAPACITOR";

static const char *const DIODE_STR = "DIODE    ";

static const char *const VCVS_STR = "VCVS     ";

static const char *const CCCS_STR = "CCCS     ";

static const char *const VCCS_STR = "VCCS     ";

static const char *const CCVS_STR = "CCVS     ";

static const char *const INDUCTOR_STR = "INDUCTOR ";

static const char *const MOSFET_STR = "MOSFET   ";

static const char *const BJT_STR = "BJT      ";

static const char *const RESISTOR_STR = "RESISTOR ";

static const char *const V_SOURCE_STR = "V-SOURCE ";

class Component {
public:
    Group group;
    char* label;
    int id;
    data_t* value;
    int nodes[MAX_NODES];
    char *type;

    Component(Group group, char *label, int id, data_t *value, const int *nodes);

    virtual ~Component();

    virtual void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) = 0;

    virtual void print();

    virtual void setControllerToGroup2IfControlled(std::vector<Component *> components);
};

class Capacitor: public Component {
public:
    //char type[10] = "CAPACITOR";
    void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) override;
    Capacitor(Group group, char *label, int id, data_t *value, int *nodes);
};

class Diode: public Component {
public:
    void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) override;
    Diode(Group group, char *label, int id, data_t *value, int *nodes);
};

class VCVS: public Component {
public:
    void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) override;
    VCVS(Group group, char *label, int id, data_t *value, int *nodes);
};

class CCCS: public Component {
public:
    char *controllerCurrent;
    void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) override;
    void print() override;
    void setControllerToGroup2IfControlled(std::vector<Component *> components) override;
    ~CCCS() override;
    CCCS(Group group, char *label, int id, data_t *value, int *nodes, char* controllerCurrent);
};

class VCCS: public Component {
public:
    void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) override;
    VCCS(Group group, char *label, int id, data_t *value, int *nodes);
};

class CCVS: public Component {
public:
    char *controllerCurrent;
    void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) override;
    void print() override;
    void setControllerToGroup2IfControlled(std::vector<Component *> components) override;
    ~CCVS() override;
    CCVS(Group group, char *label, int id, data_t *value, int *nodes, char* controllerCurrent);
};

class ISource: public Component {
public:
    void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) override;
    ISource(Group group, char *label, int id, data_t *value, int *nodes);
};

class Inductor: public Component {
public:
    void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) override;
    Inductor(Group group, char *label, int id, data_t *value, int *nodes);
};

class MOSFET: public Component {
public:
    void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) override;
    MOSFET(Group group, char *label, int id, data_t *value, int *nodes);
};

class BJT: public Component {
public:
    void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) override;
    BJT(Group group, char *label, int id, data_t *value, int *nodes);
};

class Resistor: public Component {
public:
    void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) override;
    Resistor(Group group, char *label, int id, data_t *value, int *nodes);
};

class VSource: public Component {
public:
    void stamp(std::vector<std::vector<double>> *matrix, std::vector<double> *rhs) override;
    VSource(Group group, char *label, int id, data_t *value, int *nodes);
};

class ComponentFactory {
public:
    Component *createComponent(RowType type, char *label, int id, int *nodes, data_t *value, char *controllerCurrent);
};

#endif //BINS_COMPONENT_H
