/* 
 * File:   EnginePropertiesDialog.h
 * Author: tomko
 *
 * Created on 30 sierpień 2012, 14:05
 */

#ifndef ENGINEPROPERTIESDIALOG_H
#define	ENGINEPROPERTIESDIALOG_H

#include "Properties.h"

#include <gtkmm-3.0/gtkmm.h>

/**
 * @brief Class with Engine properties dialog.
 * 
 * 
 */
class EnginePropertiesDialog : public Gtk::Dialog
{
public:
  enum Response
  {
    OK,
    CANCEL
  };

  /**
   * Constructor with setting properties.
   * @param properties Actual properties.
   */
  EnginePropertiesDialog(Properties properties);
  /**
   * Copying is not allowed.
   * @param orig Copy object.
   */
  EnginePropertiesDialog(const EnginePropertiesDialog& orig) = delete;
  /**
   * Destructor.
   */
  virtual ~EnginePropertiesDialog();

  /**
   * Save properties.
   * @param properties Object where to save properties.
   */
  void saveProperties(Properties & properties);
private:
  Gtk::SpinButton interval_button;
  Gtk::Label interval_label;

  //boxes
  Gtk::HBox main_box;
  Gtk::VBox labels_box;
  Gtk::VBox buttons_box;

};

#endif	/* ENGINEPROPERTIESDIALOG_H */

