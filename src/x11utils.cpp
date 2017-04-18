#include "x11utils.h"

_net_workarea::_net_workarea(unsigned int dx, unsigned int dy, unsigned int w,  unsigned int h):
    x(dx), y(dy), width(w), height(h) {  }

_net_workarea::_net_workarea():
    x(0), y(0), width(0), height(0) {  }

X11Utils::X11Utils() {   }

int X11Utils::getDesktopFreeAreaSize(Display* display, int screen, _net_workarea* wa)
{
  /* _NET_WORKAREA, x, y, width, height CARDINAL[][4]/32 */
  static Atom workarea = 0;
  Atom type;
  long *data;
  int format;
  unsigned long after, ndata;

  if (!workarea)
    workarea = XInternAtom(display, "_NET_WORKAREA", False);

  XGetWindowProperty(display, RootWindow(display, screen),
                     workarea, 0, LONG_MAX, False, XA_CARDINAL, &type, &format, &ndata,
                     &after, (unsigned char **)&data);
  if (type != XA_CARDINAL || data == NULL)
  {
    if (data) XFree(data);
    return 0;
  }

  wa->x = data[0];
  wa->y = data[1];
  wa->width =  data[2];
  wa->height = data[3];

  XFree(data);
  return 1;
}

_net_workarea X11Utils::initDesktopFreeAreaSize() {
    _net_workarea wa;
    getDesktopFreeAreaSize(QX11Info::display(),0, &wa);
    return wa;
}

void* X11Utils::property(Window win, Atom prop, Atom type, int &nitems)
{
    Atom type_ret;
    int format_ret;
    unsigned long items_ret;
    unsigned long after_ret;
    unsigned char *prop_data = 0;

    // на основании атома и его типа берём значение свойства
    if(XGetWindowProperty(QX11Info::display(), win, prop, 0, 0x7fffffff, False,
                            type, &type_ret, &format_ret, &items_ret,
                            &after_ret, &prop_data) != Success)
        return 0;

    // количество полученных элементов
    nitems = *((int*)prop_data);
    return prop_data;
}


unsigned long X11Utils::getDesktopCount() {
    Display *display  = QX11Info::display();
    Atom NET_NUMBER_OF_DESKTOPS = XInternAtom(display, "_NET_NUMBER_OF_DESKTOPS", False);
    int nitems = 0;
    property(QX11Info::appRootWindow(),NET_NUMBER_OF_DESKTOPS, XA_CARDINAL, nitems);

    unsigned long count = (nitems) ? nitems : 1;
    return count;
}


void X11Utils::setOnDesktops(Window winid, int all, unsigned int d) {
    Display *display  = QX11Info::display();
    if (all) { //---->если нужно на всех рабочих столах, то делаем док

        Atom dock = XInternAtom(display, "_NET_WM_WINDOW_TYPE_DOCK", False);
        XChangeProperty
        (
            display,
            winid,
            XInternAtom(display, "_NET_WM_WINDOW_TYPE", False),
            XA_ATOM ,
            32,
            PropModeReplace,
            (unsigned char *)&dock, 1
        );

    } else {  //------>иначе задаём номер рабочего стола
        unsigned int desktop = d;
        XChangeProperty
       (
            display,
            winid,
            XInternAtom(display, "_NET_WM_DESKTOP", False),
            XA_CARDINAL,
            32,
            PropModeReplace,
            (unsigned char *)&desktop, 1
       );
    }
}

void X11Utils::setStrut(Window winid, int height, int width, unsigned int start_x, unsigned int start_y, QString dockEdge) {

    Display *display  = QX11Info::display();
    int right_start_y = start_y;
    int right_end_y = height;
    int right = width + 2;
    int left = start_x + width + 2;
    long int insets[12] = {0, right, 0, 0, 0, 0, right_start_y, right_end_y, 0, 0, 0, 0};

    if (dockEdge != "Right") {
        insets[0] = left;
        insets[1] = 0;
        insets[5] = left;
        insets[6] = 0;
        insets[7] = 0;
    }

    XChangeProperty(display,
                  winid,
                 XInternAtom(QX11Info::display(), "_NET_WM_STRUT_PARTIAL", False),
                 XA_CARDINAL ,
                 32,
                 PropModeReplace,
                 (unsigned char *)&insets, 12);
}
