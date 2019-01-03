package io.adaptivecards.renderer.input;

import android.content.Context;
import android.view.ViewGroup;
import android.widget.EditText;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import io.adaptivecards.objectmodel.BaseInputElement;
import io.adaptivecards.objectmodel.HostConfig;
import io.adaptivecards.renderer.RenderedAdaptiveCard;
import io.adaptivecards.renderer.inputhandler.TextInputHandler;

public class PeoplePickerInputRenderer extends TextInputRenderer {
    private static final String ADDRESS_KEY = "Address";

    protected PeoplePickerInputRenderer()
    {
    }

    public static PeoplePickerInputRenderer getInstance()
    {
        if (s_instance == null)
        {
            s_instance = new PeoplePickerInputRenderer();
        }

        return s_instance;
    }

    private static PeoplePickerInputRenderer s_instance = null;

    @Override
    protected EditText renderInternal(
        RenderedAdaptiveCard renderedCard,
        Context context,
        ViewGroup viewGroup,
        BaseInputElement baseInputElement,
        String value,
        String placeHolder,
        final TextInputHandler textInputHandler,
        HostConfig hostConfig)
    {
        EditText editText = super.renderInternal(renderedCard, context, viewGroup, baseInputElement, value, placeHolder, textInputHandler, hostConfig);


        try {
            JSONArray jsonArray = new JSONArray(value);
            if (jsonArray.length() > 0) {
                JSONObject jsonObject = jsonArray.getJSONObject(0);
                if (jsonObject.has(ADDRESS_KEY)) {
                    editText.setText(jsonObject.getString(ADDRESS_KEY));
                }
            } else {
                editText.setText("");
            }
        } catch (JSONException e) {

        }

        return editText;
    }
}
