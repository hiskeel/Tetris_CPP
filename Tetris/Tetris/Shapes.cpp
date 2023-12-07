//#include"Shapes.h"
#include"Console.h"
void Shape::ShapeMoveDown() {
   
        for (auto& point : points) {
            point.y++;
        }
    
}