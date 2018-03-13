
#ifndef ITEM_H
#define ITEM_H

class Item{
        private:
                int x,y;                
        public:                
                Item();
                Item(int,int);
                int getX();
                int getY();
                void setX(int);
                void setY(int);                
                virtual ~Item();        
};

#endif