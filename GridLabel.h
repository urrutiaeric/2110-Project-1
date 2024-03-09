#ifndef GRIDLABEL_H
#define GRIDLABEL_H

enum GridLabel{
    RESIDENTIAL,
    INDUSTRIAL,
    COMMERCIAL,
    POWERPLANT,
    ROAD,
    POWERLINE,
    ROAD_AND_POWERLINE,
    VACANT
};

class GridLabels{
    public:
    static GridLabel getGridLabel( char l){
        switch (l){
            case 'R': return RESIDENTIAL;
            case 'I': return INDUSTRIAL;
            case 'C': return COMMERCIAL;
            case 'P': return POWERPLANT;
            case '-': return ROAD;
            case 'T': return POWERLINE;
            case '#': return ROAD_AND_POWERLINE;
            default: return VACANT;
        }
    }

    static char getLabel( GridLabel type ){
        switch ( type ){
            case RESIDENTIAL: return 'R';
            case INDUSTRIAL: return 'I';
            case COMMERCIAL: return 'C';
            case POWERPLANT: return 'P';
            case ROAD: return '-';
            case POWERLINE: return 'T';
            case ROAD_AND_POWERLINE: return '#';
            default: return ' ';

        }
    }
};

#endif /* GRIDLABEL_H */
