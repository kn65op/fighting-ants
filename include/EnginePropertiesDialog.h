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
private:

};

#endif	/* ENGINEPROPERTIESDIALOG_H */

