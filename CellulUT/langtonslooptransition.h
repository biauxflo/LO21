#ifndef LANGTONSLOOPTRANSITION_H
#define LANGTONSLOOPTRANSITION_H
#include <map>
#include <vector>
#include <iterator>
#include "Transition.h"

class LangtonsLoopTransition : public Transition
{
    std::map <std::vector <int>, int> regleLangton = {
        {{0,0,0,0,0},0},{{0,2,5,2,7},1},{{1,1,3,2,2},1},{{2,0,2,4,2},2},{{3,0,1,0,2},1
        },{{0,0,0,0,1},2},{{1,0,0,0,1},1},{{1,2,2,2,4},4},{{2,0,2,4,5},2},{{3,0,1,2,2},0
        },{{0,0,0,0,2},0},{{1,0,0,0,6},1},{{1,2,2,2,7},7},{{2,0,2,5,2},0},{{3,0,2,5,1},1
        },{{0,0,0,0,3},0},{{1,0,0,0,7},7},{{1,2,2,4,3},4},{{2,0,2,5,5},2},{{4,0,1,1,2},0
        },{{0,0,0,0,5},0},{{1,0,0,1,1},1},{{1,2,2,5,4},7},{{2,0,2,6,2},2},{{4,0,1,2,2},0
        },{{0,0,0,0,6},3},{{1,0,0,1,2},1},{{1,2,3,2,4},4},{{2,0,2,7,2},2},{{4,0,1,2,5},0
        },{{0,0,0,0,7},1},{{1,0,0,2,1},1},{{1,2,3,2,7},7},{{2,0,3,1,2},2},{{4,0,2,1,2},0
        },{{0,0,0,1,1},2},{{1,0,0,2,4},4},{{1,2,4,2,5},5},{{2,0,3,2,1},6},{{4,0,2,2,2},1
        },{{0,0,0,1,2},2},{{1,0,0,2,7},7},{{1,2,4,2,6},7},{{2,0,3,2,2},6},{{4,0,2,3,2},6
        },{{0,0,0,1,3},2},{{1,0,0,5,1},1},{{1,2,5,2,7},5},{{2,0,3,4,2},2},{{4,0,2,5,2},0
        },{{0,0,0,2,1},2},{{1,0,1,0,1},1},{{2,0,0,0,1},2},{{2,0,4,2,2},2},{{4,0,3,2,2},1
        },{{0,0,0,2,2},0},{{1,0,1,1,1},1},{{2,0,0,0,2},2},{{2,0,5,1,2},2},{{5,0,0,0,2},2
        },{{0,0,0,2,3},0},{{1,0,1,2,4},4},{{2,0,0,0,4},2},{{2,0,5,2,1},2},{{5,0,0,2,1},5
        },{{0,0,0,2,6},2},{{1,0,1,2,7},7},{{2,0,0,0,7},1},{{2,0,5,2,2},2},{{5,0,0,2,2},5
        },{{0,0,0,2,7},2},{{1,0,2,0,2},6},{{2,0,0,1,2},2},{{2,0,5,5,2},1},{{5,0,0,2,3},2
        },{{0,0,0,3,2},0},{{1,0,2,1,2},1},{{2,0,0,1,8},2},{{2,0,5,7,2},5},{{5,0,0,2,7},2
        },{{0,0,0,5,2},5},{{1,0,2,2,1},1},{{2,0,0,2,1},2},{{2,0,6,2,2},2},{{5,0,0,5,2},0
        },{{0,0,0,6,2},2},{{1,0,2,2,4},4},{{2,0,0,2,2},2},{{2,0,6,7,2},2},{{5,0,2,0,2},2
        },{{0,0,0,7,2},2},{{1,0,2,2,6},3},{{2,0,0,2,3},2},{{2,0,7,1,2},2},{{5,0,2,1,2},2
        },{{0,0,1,0,2},2},{{1,0,2,2,7},7},{{2,0,0,2,4},2},{{2,0,7,2,2},2},{{5,0,2,1,5},2
        },{{0,0,1,1,2},0},{{1,0,2,3,2},7},{{2,0,0,2,5},0},{{2,0,7,4,2},2},{{5,0,2,2,2},0
        },{{0,0,2,0,2},0},{{1,0,2,4,2},4},{{2,0,0,2,6},2},{{2,0,7,7,2},2},{{5,0,2,2,4},4
        },{{0,0,2,0,3},0},{{1,0,2,6,2},6},{{2,0,0,2,7},2},{{2,1,1,2,2},2},{{5,0,2,7,2},2
        },{{0,0,2,0,5},0},{{1,0,2,6,4},4},{{2,0,0,3,2},6},{{2,1,1,2,6},1},{{5,1,2,1,2},2
        },{{0,0,2,1,2},5},{{1,0,2,6,7},7},{{2,0,0,4,2},3},{{2,1,2,2,2},2},{{5,1,2,2,2},0
        },{{0,0,2,2,2},0},{{1,0,2,7,1},0},{{2,0,0,5,1},7},{{2,1,2,2,4},2},{{5,1,2,4,2},2
        },{{0,0,2,3,2},2},{{1,0,2,7,2},7},{{2,0,0,5,2},2},{{2,1,2,2,6},2},{{5,1,2,7,2},2
        },{{0,0,5,2,2},2},{{1,0,5,4,2},7},{{2,0,0,5,7},5},{{2,1,2,2,7},2},{{6,0,0,0,1},1
        },{{0,1,2,3,2},1},{{1,1,1,1,2},1},{{2,0,0,7,2},2},{{2,1,4,2,2},2},{{6,0,0,0,2},1
        },{{0,1,2,4,2},1},{{1,1,1,2,2},1},{{2,0,1,0,2},2},{{2,1,5,2,2},2},{{6,0,2,1,2},0
        },{{0,1,2,5,2},5},{{1,1,1,2,4},4},{{2,0,1,1,2},2},{{2,1,6,2,2},2},{{6,1,2,1,2},5
        },{{0,1,2,6,2},1},{{1,1,1,2,5},1},{{2,0,1,2,2},2},{{2,1,7,2,2},2},{{6,1,2,1,3},1
        },{{0,1,2,7,2},1},{{1,1,1,2,6},1},{{2,0,1,4,2},2},{{2,2,2,2,7},2},{{6,1,2,2,2},5
        },{{0,1,2,7,5},1},{{1,1,1,2,7},7},{{2,0,1,7,2},2},{{2,2,2,4,4},2},{{7,0,0,0,7},7
        },{{0,1,4,2,2},1},{{1,1,1,5,2},2},{{2,0,2,0,2},2},{{2,2,2,4,6},2},{{7,0,1,1,2},0
        },{{0,1,4,3,2},1},{{1,1,2,1,2},1},{{2,0,2,0,3},2},{{2,2,2,7,6},2},{{7,0,1,2,2},0
        },{{0,1,4,4,2},1},{{1,1,2,2,2},1},{{2,0,2,0,5},2},{{2,2,2,7,7},2},{{7,0,1,2,5},0
        },{{0,1,4,7,2},1},{{1,1,2,2,4},4},{{2,0,2,0,7},3},{{3,0,0,0,1},3},{{7,0,2,1,2},0
        },{{0,1,6,2,5},1},{{1,1,2,2,5},1},{{2,0,2,1,2},2},{{3,0,0,0,2},2},{{7,0,2,2,2},1
        },{{0,1,7,2,2},1},{{1,1,2,2,7},7},{{2,0,2,1,5},2},{{3,0,0,0,4},1},{{7,0,2,2,5},1
        },{{0,1,7,2,5},5},{{1,1,2,3,2},1},{{2,0,2,2,1},2},{{3,0,0,0,7},6},{{7,0,2,3,2},1
        },{{0,1,7,5,2},1},{{1,1,2,4,2},4},{{2,0,2,2,2},2},{{3,0,0,1,2},3},{{7,0,2,5,2},5
        },{{0,1,7,6,2},1},{{1,1,2,6,2},1},{{2,0,2,2,7},2},{{3,0,0,4,2},1},{{7,0,2,7,2},0
        },{{0,1,7,7,2},1},{{1,1,2,7,2},7},{{2,0,2,3,2},1},{{3,0,0,6,2},2}
    };
    
public:
    ETAT_NP::Etat& creerTransition(std::vector<ETAT_NP::Etat*> etats, ETAT_NP::Etat& etat, std::vector<CELLULE_NP::Cellule*> voisines, const unsigned int nbVoisines) override;
    LangtonsLoopTransition() = default;
};

#endif // LANGTONSLOOPTRANSITION_H
