package javap.factories;

import javap.buttons.Button;
import javap.checkboxes.Checkbox;

public interface GUIFactory {
    Button createButton();
    Checkbox createCheckbox();
}
