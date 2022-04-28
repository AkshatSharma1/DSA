int RelativeDistance(int direction,int speed1,int time1,int speed2,int time2)
{
    int relative_distance;

    if(direction == 0)
    {
        relative_distance = speed1*time1 + speed2*time2;
    }
    else
    {
        relative_distance = speed1*time1 - speed2*time2;
    }
    return relative_distance;
}