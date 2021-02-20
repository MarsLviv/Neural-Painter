#ifndef APPLOCATION_H
#define APPLOCATION_H


class AppLocation
{
public:
    AppLocation() = delete;

    static void calculateAppGeometry();


    static int appMinWidth;
    static int appMinHeight;

    static int appMoveOnX;
    static int appMoveOnY;


private:
    const static int appWidthDefault = 1300;    // TODO: move to settings
    const static int appHeightDefault = 800;
};



#endif // APPLOCATION_H
