#ifndef QWIXX_ROW_H
#define QWIXX_ROW_H
#include "Colour.h"
#include "RollOfDice.h"

template<const Colour C>
struct DataRowQR{
    static bool _isAscending(){
        bool res = false;
        switch(C){
            case RED:
            case YELLOW:
                res = true;
                break;
            }
        return res;
    }
};
template<class T, const Colour COLOUR>
class QwixxRow{
    private:
        bool _asc;
        bool _locked;
        std::vector<int> _marked;
    public:
        QwixxRow<T,COLOUR>():_asc{DataRowQR<COLOUR>::_isAscending()}, _locked{false}{}
        QwixxRow<T,COLOUR>& operator+=(const RollOfDice& rd);
        void _checkLock();
        friend std::ostream& operator<<(std::ostream &_os, QwixxRow<T,COLOUR> &qw){
            _os<<"|";
            if(qw._asc){
                bool flag = false;
                for(int i = 0; i < 11; ++i){
                    
                    for(int j = 0; j < qw._marked.size(); ++j){
                    if(qw._marked[j] == i+2)  {
                        flag = true;
                    }
                }
                
                if(flag){
                    _os<<"XX";
                    flag = false;
                }else if(i+2 < 10){
                    _os<<" " << i+2;
                }else{
                    _os<<i+2;
                }
                _os<<"|";
                }
            }else{
                bool flag = false;
                for(int i = 14; i > 3; --i){
                    for(int j = 0; j < qw._marked.size(); ++j){
                    if(qw._marked[j] == i-2)  {
                        flag = true;
                    }
                }
                
                if(flag){
                    _os<<"XX";
                    flag = false;
                }else if(i-2 < 10){
                    _os<<" " << i-2;
                }else{
                    _os<<i-2;
                }
                _os<<"|";
                }
            }
            if(qw._locked){
                _os<<" L";
            }else{
                _os<<" U";
            }
        }
};

template<class T, const Colour COLOUR>
QwixxRow<T,COLOUR>& QwixxRow<T,COLOUR>::operator+=(const RollOfDice& rd){
    
    if(!_locked){
        if(_asc){
        for(int i = 0; i < _marked.size(); ++i){
            if(_marked[i] >= rd){
                throw "INVALID";
            }
        }
        
        _marked.push_back(rd);
        _checkLock();
    }else{
        for(int i = 0; i < _marked.size(); ++i){
            if(_marked[i] <= rd){
                throw "INVALID";
            }
        }
        _marked.push_back(rd);
        _checkLock();
    }
    }else{
        throw "Invalid";
    }
    
}

template<class T, const Colour COLOUR>
void QwixxRow<T,COLOUR>::_checkLock(){
    if(_asc){
        bool flag = false;
        for(int i = 0; i < _marked.size(); ++i){
            if(_marked[i] == 12){
                flag = true;
            }
        }
        if(_marked.size() >= 5 && flag){
            _locked = true;
        }
    }else{
        bool flag = false;
        for(int i = 0; i < _marked.size(); ++i){
            if(_marked[i] == 2){
                flag = true;
            }
        }
        if(_marked.size() >= 5 && flag){
            _locked = true;
        }
    }
}
#endif


