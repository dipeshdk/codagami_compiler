struct coord{
    int x;
    int y;
};

int calculateDistanceSquare(struct coord point1, struct coord point2){
    int xDiff = point1.x - point2.x;
    int yDiff = point1.y - point2.y;
    int distance = xDiff*xDiff + yDiff*yDiff; 
    return distance;
}

void xProjection(struct coord point){
    struct coord projection;
    projection.x = point.x;
    projection.y = 0;
}

int main(){
    struct coord point1;
    struct coord point2;
    int dist;
    struct coord projection;

    point1.x = 1;
    point1.y = 2;
    point2.x = 3;
    point2.y = 4;

    dist = calculateDistanceSquare(point1, point2);
    xProjection(point1);
    return 0;
}