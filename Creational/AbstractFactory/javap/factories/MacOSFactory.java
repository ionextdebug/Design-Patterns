package javap.factories;

import javap.buttons.Button;
import javap.buttons.MacOSButton;
import javap.checkboxes.Checkbox;
import javap.checkboxes.MacOSCheckbox;

public class MacOSFactory implements GUIFactory {

    @Override
    public Button createButton(){
        return new MacOSButton();
    }

    @Override
    public Checkbox createCheckbox(){
        return new MacOSCheckbox();
    }

}
