/* 
 * File:   MainWindow.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 13:03
 */

#ifndef MAINWINDOWS_H
#define	MAINWINDOWS_H

#include <gtkmm-3.0/gtkmm.h>

class MainWindow : public Gtk::Window
{
public:
  MainWindow();
  MainWindow(const MainWindow& orig) = delete;
  ~MainWindow();
private:

};

#endif	/* MAINWINDOWS_H */

