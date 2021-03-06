/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.1

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

#define LINE_WIDTH 20
#define GROUP_CHANNELS 4
#define METER_GROUP_SPACE 6

//==============================================================================
Mcfx_gain_delayAudioProcessorEditor::Mcfx_gain_delayAudioProcessorEditor (Mcfx_gain_delayAudioProcessor* ownerFilter)
    : AudioProcessorEditor (ownerFilter)
{
    
    tooltipWindow.setMillisecondsBeforeTipAppears (700); // tooltip delay
    
    addAndMakeVisible (lbl_gd = new Label ("new label",
                                           TRANS("mcfx_gain_delay")));
    lbl_gd->setFont (Font (15.00f, Font::plain));
    lbl_gd->setJustificationType (Justification::centredLeft);
    lbl_gd->setEditable (false, false, false);
    lbl_gd->setColour (Label::textColourId, Colours::yellow);
    lbl_gd->setColour (TextEditor::textColourId, Colours::black);
    lbl_gd->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("gain [dB]\n")));
    label2->setFont (Font (13.00f, Font::plain));
    label2->setJustificationType (Justification::centredRight);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::white);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("delay [ms]\n")));
    label3->setFont (Font (13.00f, Font::plain));
    label3->setJustificationType (Justification::centredRight);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colours::white);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    addAndMakeVisible (btn_paste_gain = new ImageButton ("new button"));
    btn_paste_gain->setTooltip (TRANS("paste gain values from clipboard"));
    btn_paste_gain->addListener (this);

    btn_paste_gain->setImages (false, true, true,
                                ImageCache::getFromMemory (clipboard35_grey_png, clipboard35_grey_pngSize), 1.000f, Colour (0x00000000),
                                ImageCache::getFromMemory (clipboard35_png, clipboard35_pngSize), 1.000f, Colour (0x00000000),
                                Image(), 1.000f, Colour (0x00000000));
    
    addAndMakeVisible (btn_paste_gain2 = new ImageButton ("new button"));
    btn_paste_gain2->setTooltip (TRANS("paste delay values from clipboard"));
    btn_paste_gain2->addListener (this);

    btn_paste_gain2->setImages (false, true, true,
                                ImageCache::getFromMemory (clipboard35_grey_png, clipboard35_grey_pngSize), 1.000f, Colour (0x00000000),
                                ImageCache::getFromMemory (clipboard35_png, clipboard35_pngSize), 1.000f, Colour (0x00000000),
                                Image(), 1.000f, Colour (0x00000000));

    //[UserPreSize]
    //[/UserPreSize]
/*
    addAndMakeVisible (lbl_ch = new Label ("new label",
                                           TRANS("1")));
    lbl_ch->setFont (Font (15.00f, Font::plain));
    lbl_ch->setJustificationType (Justification::centredRight);
    lbl_ch->setEditable (false, false, false);
    lbl_ch->setColour (Label::textColourId, Colours::white);
    lbl_ch->setColour (TextEditor::textColourId, Colours::black);
    lbl_ch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (sld_del = new Slider ("new slider"));
    sld_del->setTooltip (TRANS("delay ch 1"));
    sld_del->setRange (0, 500, 0.1);
    sld_del->setSliderStyle (Slider::Rotary);
    sld_del->setTextBoxStyle (Slider::TextBoxLeft, false, 50, 18);
    sld_del->setColour (Slider::rotarySliderFillColourId, Colours::red);
    sld_del->addListener (this);
    
    addAndMakeVisible (sld_gain = new Slider ("new slider"));
    sld_gain->setTooltip (TRANS("gain ch 1"));
    sld_gain->setRange (-18, 18, 0.01);
    sld_gain->setSliderStyle (Slider::Rotary);
    sld_gain->setTextBoxStyle (Slider::TextBoxLeft, false, 50, 18);
    sld_gain->setColour (Slider::rotarySliderFillColourId, Colours::yellow);
    sld_gain->addListener (this);
*/
  
  DrawableImage phase_normal, phase_over, phase_inv;
  phase_normal.setImage(ImageCache::getFromMemory (phase_symbol_png, phase_symbol_pngSize));
  phase_over.setImage(ImageCache::getFromMemory (phase_symbol_over_png, phase_symbol_over_pngSize));
  phase_inv.setImage(ImageCache::getFromMemory (phase_symbol_inv_png, phase_symbol_inv_pngSize));
  
    // create labels and knobs!
    for (int i=0; i<NUM_CHANNELS; i++)
    {
        if (Label* const LABEL = new Label ("new label", String (i+1)))
        {
            lbl_ch.add(LABEL);
            addChildComponent(lbl_ch.getUnchecked(i));
            lbl_ch.getUnchecked(i)->setVisible(true);
            lbl_ch.getUnchecked(i)->setFont (Font (15.00f, Font::plain));
            lbl_ch.getUnchecked(i)->setJustificationType (Justification::centredRight);
            lbl_ch.getUnchecked(i)->setEditable (false, false, false);
            lbl_ch.getUnchecked(i)->setColour (Label::textColourId, Colours::white);
            lbl_ch.getUnchecked(i)->setColour (TextEditor::textColourId, Colours::black);
            lbl_ch.getUnchecked(i)->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
        }
        if (Slider* const DELAY = new Slider (String(2*i+1)))
        {
            sld_del.add(DELAY);
            addChildComponent(sld_del.getUnchecked(i));
            sld_del.getUnchecked(i)->setVisible(true);
            
            String tooltip = "delay ch";
            tooltip.append(String(i+1), 3);
            
            sld_del.getUnchecked(i)->setTooltip(tooltip);
            
            sld_del.getUnchecked(i)->setRange (0, MAX_DELAYTIME_S*1000.f, 0.1);
            sld_del.getUnchecked(i)->setSliderStyle (Slider::Rotary);
            sld_del.getUnchecked(i)->setTextBoxStyle (Slider::TextBoxLeft, false, 50, 18);
            sld_del.getUnchecked(i)->setColour (Slider::rotarySliderFillColourId, Colours::red);
            sld_del.getUnchecked(i)->addListener (this);
            sld_del.getUnchecked(i)->setExplicitFocusOrder(NUM_CHANNELS+i);
            sld_del.getUnchecked(i)->setDoubleClickReturnValue(true, 0.f);
        }
        if (Slider* const GAIN = new Slider (String(2*i)))
        {
            sld_gain.add(GAIN);
            addChildComponent(sld_gain.getUnchecked(i));
            sld_gain.getUnchecked(i)->setVisible(true);
            
            String tooltip = "gain ch";
            tooltip.append(String(i+1), 3);
            
            sld_gain.getUnchecked(i)->setTooltip(tooltip);
            
            sld_gain.getUnchecked(i)->setRange (-18, 18, 0.01);
            sld_gain.getUnchecked(i)->setSliderStyle (Slider::Rotary);
            sld_gain.getUnchecked(i)->setTextBoxStyle (Slider::TextBoxLeft, false, 50, 18);
            sld_gain.getUnchecked(i)->setColour (Slider::rotarySliderFillColourId, Colours::yellow);
            sld_gain.getUnchecked(i)->addListener (this);
            sld_gain.getUnchecked(i)->setExplicitFocusOrder(i);
            sld_gain.getUnchecked(i)->setDoubleClickReturnValue(true, 0.f);
        }
      if (DrawableButton* const PHASE = new DrawableButton (String(i), DrawableButton::ButtonStyle::ImageFitted))
      {
        btn_phase.add(PHASE);
        addChildComponent(btn_phase.getUnchecked(i));
        btn_phase.getUnchecked(i)->setVisible(true);
        btn_phase.getUnchecked(i)->setTooltip (TRANS("phase normal"));
        btn_phase.getUnchecked(i)->addListener (this);
        
        btn_phase.getUnchecked(i)->setImages (&phase_normal,
                                              &phase_over,
                                              &phase_inv,
                                              &phase_normal,
                                              &phase_inv,
                                              &phase_over,
                                              &phase_inv,
                                              &phase_inv);
        
        btn_phase.getUnchecked(i)->setColour(DrawableButton::ColourIds::backgroundColourId, Colours::transparentBlack);
        btn_phase.getUnchecked(i)->setColour(DrawableButton::ColourIds::backgroundOnColourId, Colours::transparentBlack);
        
        btn_phase.getUnchecked(i)->setClickingTogglesState(true);
        
      }
    }
    
    if (NUM_CHANNELS > GROUP_CHANNELS)
        setSize (445, 60+NUM_CHANNELS/2*LINE_WIDTH + METER_GROUP_SPACE * NUM_CHANNELS/GROUP_CHANNELS);
    else
        setSize (220, 60+NUM_CHANNELS*LINE_WIDTH + METER_GROUP_SPACE*NUM_CHANNELS/GROUP_CHANNELS);
    


    // register as change listener (gui/dsp sync)
    ownerFilter->addChangeListener(this);
    ownerFilter->sendChangeMessage(); // get status from dsp
    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Mcfx_gain_delayAudioProcessorEditor::~Mcfx_gain_delayAudioProcessorEditor()
{
    Mcfx_gain_delayAudioProcessor* ourProcessor = getProcessor();
    
    // remove me as listener for changes
    ourProcessor->removeChangeListener(this);
    
    lbl_gd = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    btn_paste_gain = nullptr;
    btn_paste_gain2 = nullptr;
  
}

//==============================================================================
void Mcfx_gain_delayAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff1a1a1a));

    g.setGradientFill (ColourGradient (Colour (0xff4e4e4e),
                                       (float) (proportionOfWidth (0.6400f)), (float) (proportionOfHeight (0.6933f)),
                                       Colours::black,
                                       (float) (proportionOfWidth (0.1143f)), (float) (proportionOfHeight (0.0800f)),
                                       true));
    g.fillRect (0, 0, this->getBounds().getWidth(), this->getBounds().getHeight());
    
    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Mcfx_gain_delayAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    lbl_gd->setBounds (0, 0, 115, 16);
    label2->setBounds (40, 26, 66, 16);
    label3->setBounds (123, 26, 75, 16);
    
    btn_paste_gain->setBounds (29, 26, 16, 16);
    btn_paste_gain2->setBounds (109, 26, 16, 16);
  
    int num_groups_first_col = (jmax(NUM_CHANNELS,GROUP_CHANNELS)/GROUP_CHANNELS)*0.5f + 0.5f;
  
    for (int i=0; i < NUM_CHANNELS; i++)
    {
        int i_rel = i;
        
        int group = i / GROUP_CHANNELS;
      
        int column = 0;
        
        if (group >= num_groups_first_col)
        {
            column = 1;
            i_rel = i-num_groups_first_col*GROUP_CHANNELS;
            group -= num_groups_first_col;
        }
        
        int y = 48 + i_rel * LINE_WIDTH + group * METER_GROUP_SPACE;
        
        int x_offset = column * 225;
        
        //int y=10;
        if (lbl_ch.size() > i)
            lbl_ch.getUnchecked(i)->setBounds(-2+x_offset, y, 29, 16);
        if (sld_del.size() > i)
            sld_del.getUnchecked(i)->setBounds(109+x_offset, y-3, 84, 24);
        if (sld_gain.size() > i)
            sld_gain.getUnchecked(i)->setBounds(28+x_offset, y-3, 77, 24);
        if (btn_phase.size() > i)
            btn_phase.getUnchecked(i)->setBounds (189+x_offset, y, 19, 19);
          
    }
    
    //lbl_ch->setBounds (-2, 48, 29, 16);
    //sld_del->setBounds (117, 45, 84, 24);
    //sld_gain->setBounds (30, 45, 77, 24);
}

void Mcfx_gain_delayAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    Mcfx_gain_delayAudioProcessor* ourProcessor = getProcessor();
    
    int slider_nr = sliderThatWasMoved->getName().getIntValue();
  
    int param_nr = floorf(slider_nr*1.5f);
  
    if (slider_nr % 2 == 0)
        ourProcessor->setParameterNotifyingHost(param_nr, (float)sliderThatWasMoved->getValue()/36.f+0.5f);
    else
        ourProcessor->setParameterNotifyingHost(param_nr, (float)sliderThatWasMoved->getValue()/(MAX_DELAYTIME_S*1000.f));
    
    /*
    if (sliderThatWasMoved == sld_del)
    {
        //[UserSliderCode_sld_del] -- add your slider handling code here..
        //[/UserSliderCode_sld_del]
    }
    else if (sliderThatWasMoved == sld_gain)
    {
        //[UserSliderCode_sld_gain] -- add your slider handling code here..
        //[/UserSliderCode_sld_gain]
    }
     */
    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void Mcfx_gain_delayAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
  
  Mcfx_gain_delayAudioProcessor* ourProcessor = getProcessor();
  
  if ((buttonThatWasClicked != btn_paste_gain) && (buttonThatWasClicked != btn_paste_gain2))
  {
    int ch_nr = buttonThatWasClicked->getName().getIntValue();
    float val = 0.f;
    
    if (buttonThatWasClicked->getToggleState())
      val = 1.f;
    
    ourProcessor->setParameterNotifyingHost(ch_nr*3+2, val);
                                            
  } else {
    
    
    Array<float> values;
    
    // get string from clipboard and remove any nonnumbers
    String clip (SystemClipboard::getTextFromClipboard());
    
    if (clip.isNotEmpty())
    {
      
      clip = clip.replaceCharacter(',', ' ');
      clip = clip.replaceCharacter(';', ' ');
      clip = clip.replaceCharacter('\n', ' ');
      clip = clip.replaceCharacter('\t', ' ');
      clip = clip.retainCharacters("-0123456789. ");
      
      while (clip.isNotEmpty()) {
        float nr = clip.upToFirstOccurrenceOf(" ", false, true).getFloatValue();
        values.add(nr);
        clip = clip.fromFirstOccurrenceOf(" ", false, true).trim();
      }
    }
    
    if (buttonThatWasClicked == btn_paste_gain)
    {
      if (values.size() > 0)
      {
        for (int i=0; i < jmin(NUM_CHANNELS, values.size()); i++) {
          sld_gain.getUnchecked(i)->setValue(values.getUnchecked(i), sendNotification);
        }
      }
      
    }
    else if (buttonThatWasClicked == btn_paste_gain2)
    {
      if (values.size() > 0)
      {
        for (int i=0; i < jmin(NUM_CHANNELS, values.size()); i++) {
          sld_del.getUnchecked(i)->setValue(values.getUnchecked(i), sendNotification);
        }
      }
    }
  }
  //[UserbuttonClicked_Post]
  //[/UserbuttonClicked_Post]
}

void Mcfx_gain_delayAudioProcessorEditor::changeListenerCallback (ChangeBroadcaster *source)
{
    Mcfx_gain_delayAudioProcessor* ourProcessor = getProcessor();
    
    for (int i=0; i < NUM_CHANNELS; i++)
    {
        // sld_del.getUnchecked(i)->setValue(ourProcessor->getParameter(3*i+2) * MAX_DELAYTIME_S*1000,dontSendNotification);
        sld_del.getUnchecked(i)->setValue(ourProcessor->getParameter(3*i+1) * MAX_DELAYTIME_S*1000,dontSendNotification);
        sld_gain.getUnchecked(i)->setValue((ourProcessor->getParameter(3*i)-0.5f)*36.f,dontSendNotification);
      
        if (ourProcessor->getParameter(3*i+2) > 0.5)
        {
          String tooltip = "ch";
          tooltip.append(String(i+1), 3);
          tooltip << " phase inverted";
          btn_phase.getUnchecked(i)->setToggleState(true, dontSendNotification);
          btn_phase.getUnchecked(i)->setTooltip (tooltip);
        } else {
          String tooltip = "ch";
          tooltip.append(String(i+1), 3);
          tooltip << " phase normal";
          btn_phase.getUnchecked(i)->setToggleState(false, dontSendNotification);
          btn_phase.getUnchecked(i)->setTooltip (tooltip);
        }
      
    }
    
    /*
    sld_az->setValue((ourProcessor->getParameter(Ambix_encoderAudioProcessor::AzimuthParam) - 0.5f) * 360.f, dontSendNotification);
    sld_el->setValue((ourProcessor->getParameter(Ambix_encoderAudioProcessor::ElevationParam) - 0.5f) * 360.f, dontSendNotification);
    sld_size->setValue(ourProcessor->getParameter(Ambix_encoderAudioProcessor::SizeParam), dontSendNotification);
     */
}

//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Mcfx_gain_delayAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="Mcfx_gain_delayAudioProcessor* ownerFilter"
                 variableInitialisers="AudioProcessorEditor (ownerFilter)" snapPixels="8"
                 snapActive="0" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="200" initialHeight="210">
  <BACKGROUND backgroundColour="ff1a1a1a"/>
  <LABEL name="new label" id="b45e45d811b90270" memberName="lbl_gd" virtualName=""
         explicitFocusOrder="0" pos="0 0 115 16" textCol="ffffff00" edTextCol="ff000000"
         edBkgCol="0" labelText="mcfx_gain_delay" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="d5c1a3078147bf28" memberName="sld_del"
          virtualName="" explicitFocusOrder="0" pos="117 45 84 24" tooltip="delay ch 1"
          rotarysliderfill="ffff0000" min="0" max="500" int="0.10000000000000000555"
          style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="50"
          textBoxHeight="18" skewFactor="1"/>
  <SLIDER name="new slider" id="edc665213f83e06b" memberName="sld_gain"
          virtualName="" explicitFocusOrder="0" pos="30 45 77 24" tooltip="gain ch 1"
          thumbcol="ff5a5a90" trackcol="ffffff00" rotarysliderfill="ffffff00"
          rotaryslideroutline="ffffff00" min="-18" max="18" int="0.010000000000000000208"
          style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="50"
          textBoxHeight="18" skewFactor="1"/>
  <LABEL name="new label" id="e30a8f204d299927" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="40 26 66 16" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="gain [dB]&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="a7997dcae0239c4c" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="123 26 75 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="delay [ms]&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="5189e110ab7987d1" memberName="lbl_ch" virtualName=""
         explicitFocusOrder="0" pos="-2 48 29 16" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="1" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <IMAGEBUTTON name="new button" id="fb278a9f97bfef46" memberName="btn_paste_gain"
               virtualName="" explicitFocusOrder="0" pos="32 26 16 16" tooltip="paste gain values from clipboard"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="clipboard35_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="new button" id="548c7fabb48b0c32" memberName="btn_paste_gain2"
               virtualName="" explicitFocusOrder="0" pos="117 26 16 16" tooltip="paste delay values from clipboard"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="clipboard35_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: clipboard35_png, 346, "clipboard35.png"
static const unsigned char resource_Mcfx_gain_delayAudioProcessorEditor_clipboard35_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,6,0,0,0,224,119,61,248,0,0,0,6,98,75,71,
    68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,19,21,17,27,160,237,73,232,0,0,0,231,73,68,65,84,72,199,237,149,177,109,195,
    48,16,69,31,13,3,201,10,238,60,130,17,164,55,55,72,157,105,36,47,16,100,160,20,78,237,37,228,5,82,164,82,247,210,144,128,45,196,22,9,51,69,0,191,134,194,81,159,159,184,35,121,112,5,117,165,30,60,231,160,
    174,40,100,57,51,255,10,60,3,187,147,88,151,226,111,220,138,218,171,78,98,170,125,237,66,81,29,189,141,81,141,151,82,20,129,135,244,253,9,236,43,246,23,129,109,210,199,169,246,183,26,236,67,8,125,77,26,
    147,65,113,145,59,181,163,17,75,218,18,167,7,160,181,193,118,154,174,69,133,120,23,42,200,119,103,193,31,115,55,184,27,252,3,131,124,147,199,6,189,195,107,6,239,105,124,188,160,47,125,252,242,83,191,1,
    94,128,99,241,238,230,186,88,254,71,125,82,191,212,65,93,183,174,193,6,248,0,190,129,24,66,24,66,69,126,231,58,93,78,227,49,47,94,85,192,66,6,117,125,170,253,1,108,188,230,234,114,55,239,250,0,0,0,0,73,
    69,78,68,174,66,96,130,0,0};

const char* Mcfx_gain_delayAudioProcessorEditor::clipboard35_png = (const char*) resource_Mcfx_gain_delayAudioProcessorEditor_clipboard35_png;
const int Mcfx_gain_delayAudioProcessorEditor::clipboard35_pngSize = 346;

// JUCER_RESOURCE: clipboard35_grey_png, 363, "clipboard35_grey.png"
static const unsigned char resource_Mcfx_gain_delayAudioProcessorEditor_clipboard35_grey_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,6,0,0,0,224,119,61,248,0,0,0,6,98,75,
    71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,27,16,56,59,28,186,28,207,0,0,0,248,73,68,65,84,72,199,237,149,161,142,194,
    64,16,134,191,146,38,135,194,243,22,21,231,187,18,5,122,94,226,94,161,197,157,186,220,91,140,71,33,16,197,243,16,84,225,79,21,5,102,54,217,144,94,187,133,34,72,248,205,38,179,153,255,223,249,39,59,147,
    208,1,17,153,3,27,224,51,8,31,128,165,170,158,136,64,218,115,47,70,190,14,98,133,197,127,198,16,152,1,168,106,25,84,85,248,120,12,18,75,114,192,22,248,224,126,156,129,133,170,86,109,21,184,128,124,15,
    84,3,136,29,144,91,190,187,205,109,179,168,10,45,233,131,136,148,38,16,221,131,194,124,30,5,41,227,194,89,69,79,19,200,111,237,26,34,176,190,163,55,197,132,39,227,45,240,22,120,1,1,255,209,154,71,137,
    68,228,210,37,240,107,231,244,159,252,216,225,231,71,125,6,172,128,58,181,141,213,0,223,29,175,139,21,168,108,135,127,1,53,224,198,238,65,6,236,128,63,192,169,234,49,25,224,111,223,166,243,85,214,158,
    124,232,52,205,187,54,87,27,57,192,21,140,163,68,213,64,152,116,144,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* Mcfx_gain_delayAudioProcessorEditor::clipboard35_grey_png = (const char*) resource_Mcfx_gain_delayAudioProcessorEditor_clipboard35_grey_png;
const int Mcfx_gain_delayAudioProcessorEditor::clipboard35_grey_pngSize = 363;


// JUCER_RESOURCE: phase_symbol_png, 2992, "phase_symbol.png"
static const unsigned char resource_Mcfx_gain_delayAudioProcessorEditor_phase_symbol_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,49,0,0,0,49,8,6,0,0,1,4,155,113,138,0,0,0,9,112,72,89,
  115,0,0,14,197,0,0,14,197,1,71,108,236,255,0,0,11,98,73,68,65,84,120,218,205,90,105,80,84,217,21,190,224,67,5,65,20,69,140,27,98,185,239,104,66,80,131,226,194,104,33,113,139,34,238,90,174,196,45,150,63,
  76,25,171,172,82,113,41,117,84,220,17,84,68,203,224,174,40,50,46,131,203,104,20,151,148,107,92,10,40,13,229,50,136,34,8,42,42,228,251,238,244,109,187,155,126,77,55,50,73,78,213,211,238,190,239,221,123,
  238,185,231,124,231,59,231,161,149,148,148,8,37,131,6,13,186,126,228,200,145,223,170,239,26,255,25,53,106,84,73,173,90,181,68,163,70,141,196,172,89,179,228,221,209,209,209,78,114,144,3,148,248,248,120,
  49,122,244,104,225,228,228,36,94,191,126,237,165,113,42,62,193,129,188,188,60,81,169,82,37,121,227,136,17,35,126,212,184,6,167,10,14,14,22,190,190,190,34,46,46,78,76,156,56,81,132,133,133,197,105,106,
  113,14,80,56,64,153,57,115,230,122,77,45,206,53,56,21,159,224,128,212,86,109,229,202,149,43,131,30,60,120,224,55,126,252,248,53,198,109,40,213,41,55,111,222,252,94,110,65,253,184,126,253,122,97,34,37,
  70,37,48,183,200,202,202,18,13,26,52,248,106,145,13,27,54,200,141,182,104,209,226,235,0,231,227,163,166,243,12,27,54,172,187,81,229,234,213,171,231,123,123,123,191,74,79,79,247,51,83,151,226,225,225,81,
  50,97,194,4,97,41,247,238,221,19,103,207,158,117,50,59,17,117,179,181,7,40,109,218,180,145,219,253,240,225,131,136,137,137,113,210,104,16,211,155,185,93,238,140,82,84,84,36,182,110,221,106,252,94,181,
  106,85,65,85,53,90,208,114,102,238,124,198,140,25,162,114,229,202,162,101,203,150,102,99,220,155,70,147,39,36,36,124,79,21,148,253,76,37,36,36,196,236,59,141,33,247,164,54,57,101,202,148,18,170,96,77,
  104,206,160,160,160,139,165,172,167,36,50,50,50,249,253,251,247,85,118,238,220,217,219,114,204,120,164,105,105,105,127,130,138,7,120,130,46,46,46,242,82,126,0,115,95,134,38,221,140,15,96,63,255,132,53,
  58,242,102,29,83,119,197,113,20,230,231,231,187,201,7,120,179,40,67,112,20,174,231,206,157,11,214,92,93,93,75,38,79,158,108,28,128,222,226,227,199,143,226,203,151,47,242,154,54,109,154,60,27,154,124,207,
  158,61,169,154,233,205,133,133,133,34,34,34,66,40,107,241,80,183,109,219,38,111,166,96,242,175,155,166,108,223,190,93,14,242,196,225,22,242,108,44,28,223,252,129,128,128,0,121,226,136,101,227,172,60,121,
  179,7,78,156,56,33,250,247,239,47,245,133,105,5,207,133,87,113,113,177,216,188,121,179,152,62,125,186,249,3,56,114,39,218,155,27,85,179,42,177,188,249,210,165,75,55,53,3,190,20,142,27,55,206,205,150,89,
  221,221,221,79,223,184,113,227,59,249,192,219,183,111,171,213,173,91,247,231,240,240,112,111,107,55,103,100,100,156,61,126,252,248,119,102,155,126,241,226,69,29,254,15,84,57,14,132,241,171,82,165,74,209,
  195,135,15,125,158,61,123,86,207,108,15,214,156,79,201,162,69,139,18,151,45,91,22,30,24,24,40,218,181,107,87,106,60,55,55,151,251,162,186,153,183,110,221,106,162,55,143,102,249,3,125,241,229,203,151,29,
  155,53,107,38,191,155,58,131,165,212,168,81,67,158,10,196,79,57,55,109,72,179,232,70,197,194,133,11,15,112,114,248,176,40,175,240,144,184,224,190,125,251,178,149,57,53,101,150,236,236,236,112,165,189,
  53,161,75,39,39,39,11,236,82,186,53,205,71,39,52,149,148,148,20,209,181,107,87,169,36,15,183,118,237,218,185,175,94,189,170,33,23,73,77,77,13,183,102,115,10,99,131,136,72,179,13,29,58,212,108,12,193,197,
  180,37,63,187,185,185,25,115,142,146,145,35,71,122,210,41,52,34,140,222,2,7,14,28,144,94,111,137,121,199,142,29,19,79,158,60,145,19,51,148,144,253,74,45,160,132,94,167,17,194,136,74,214,4,7,40,67,141,
  114,244,232,81,241,244,233,211,82,26,83,9,91,66,183,214,136,145,99,199,142,45,161,167,88,10,108,42,39,222,184,113,99,169,144,84,194,49,127,127,127,221,69,24,55,242,76,224,227,153,61,122,244,48,230,146,
  189,123,247,202,131,54,213,152,32,71,88,82,66,148,105,219,182,109,41,83,154,10,206,242,36,2,51,84,45,210,164,119,239,222,151,136,199,6,154,81,234,129,169,83,167,58,228,202,6,136,8,53,139,19,149,29,144,
  16,74,108,105,87,150,248,248,248,36,195,124,27,67,67,67,147,117,35,30,48,35,211,14,147,5,92,246,200,224,193,131,61,9,235,182,132,102,1,10,250,224,234,108,21,86,108,97,151,146,79,159,62,185,1,249,151,95,
  191,126,189,19,188,209,165,113,227,198,25,112,253,69,8,222,127,149,245,172,166,55,128,137,60,91,181,106,245,76,211,52,183,110,221,186,9,79,79,79,35,127,252,252,249,115,0,114,81,196,237,219,183,9,69,197,
  112,146,97,3,7,14,60,100,247,2,224,98,249,96,140,238,3,6,12,176,169,93,251,246,237,121,57,159,62,125,250,32,8,235,103,4,166,143,151,151,215,107,221,5,16,108,46,192,154,34,189,136,213,19,103,103,103,38,
  122,109,248,240,225,57,72,211,147,241,124,172,213,5,96,142,162,111,241,36,152,84,96,55,219,176,224,23,44,184,195,108,1,82,197,111,153,92,73,157,58,117,24,184,49,240,192,195,64,140,92,185,64,84,84,212,
  94,84,7,162,162,4,140,82,131,167,253,27,25,210,67,46,176,106,213,170,136,49,99,198,216,124,232,234,213,171,226,238,221,187,18,82,234,213,171,39,16,80,194,52,70,224,202,130,94,213,185,243,47,225,128,67,
  119,71,16,247,214,224,102,67,112,56,182,98,64,108,217,178,69,50,125,30,38,76,41,114,114,114,68,108,108,172,17,113,21,180,179,210,81,11,240,94,184,238,49,13,154,111,239,219,183,175,213,201,9,209,156,156,
  254,143,228,98,25,39,114,17,114,51,46,14,155,27,203,12,37,189,122,245,202,209,128,126,158,122,218,115,114,106,98,57,57,5,222,98,252,60,105,210,36,97,141,111,227,28,26,106,180,167,158,48,9,129,144,155,
  253,166,106,9,165,53,115,249,201,147,39,229,103,171,145,172,7,102,42,131,129,193,25,127,179,150,237,88,85,62,127,254,92,31,139,120,136,122,209,169,167,181,169,173,121,22,32,106,250,11,208,35,116,7,53,
  77,236,218,181,75,230,108,107,172,194,0,241,18,147,116,231,40,40,40,96,94,172,108,57,64,173,129,154,114,114,107,30,66,97,93,77,233,212,169,147,30,17,184,167,33,193,199,33,120,34,77,7,76,109,205,131,62,
  124,248,176,104,221,186,53,221,78,154,137,99,73,73,73,82,123,61,130,96,224,239,239,181,229,203,151,255,25,4,32,178,67,135,14,242,199,71,143,30,9,48,65,51,173,207,159,63,47,80,112,138,251,247,239,155,145,
  128,178,114,54,206,230,141,132,10,104,244,2,11,72,119,105,222,188,185,188,76,5,10,200,203,17,193,238,142,157,58,117,106,160,92,32,51,51,243,55,160,36,95,96,2,231,138,0,59,56,71,97,86,86,214,71,51,184,
  94,189,122,117,232,142,29,59,82,8,183,223,42,32,120,31,65,39,195,205,22,0,30,253,0,143,137,72,76,76,252,123,253,250,245,203,61,57,106,137,60,204,227,101,53,163,129,150,39,34,167,230,204,155,55,111,31,
  18,125,77,71,38,6,41,120,132,201,93,49,121,35,155,73,191,79,159,62,103,192,113,188,16,60,119,176,19,31,80,19,111,91,19,35,135,167,163,4,240,128,43,79,88,188,120,241,101,187,105,11,146,135,228,251,107,
  215,174,253,11,92,249,175,136,137,79,192,251,92,160,102,209,187,119,239,156,64,61,155,245,236,217,51,53,33,33,97,204,146,37,75,222,234,30,184,61,196,203,150,48,97,69,71,71,207,187,118,237,90,11,120,142,
  39,49,172,90,181,106,146,71,17,106,88,50,112,13,162,2,113,143,109,55,40,200,128,45,106,218,180,233,115,156,125,242,220,185,115,23,122,123,123,103,151,219,107,29,185,25,138,84,94,177,98,69,252,186,117,
  235,134,65,161,74,29,59,118,148,61,51,248,134,208,75,140,54,132,16,232,75,164,90,176,96,65,36,193,2,150,47,174,89,179,230,207,49,49,49,227,67,66,66,126,168,208,77,160,94,221,191,114,229,202,161,126,126,
  126,178,222,100,171,165,34,5,216,43,136,136,184,136,39,117,81,61,166,204,153,51,167,24,69,115,62,202,209,225,140,212,114,109,130,132,21,153,230,214,254,253,251,91,177,220,212,235,18,254,26,194,77,25,0,
  210,19,167,146,210,175,95,63,1,61,134,163,120,217,103,247,38,104,121,184,205,80,246,47,28,101,221,21,45,196,72,242,231,131,7,15,38,130,42,197,225,148,6,19,121,116,55,65,159,71,17,154,3,75,184,255,175,
  149,183,20,4,190,64,201,239,78,92,198,198,126,2,123,29,80,106,19,172,210,80,72,229,32,88,43,89,182,120,191,69,20,165,51,101,94,246,10,81,204,146,133,49,177,128,73,4,19,255,21,68,107,38,53,209,51,156,66,
  185,55,64,101,83,83,83,37,85,49,156,170,46,195,51,84,46,2,57,192,90,11,65,156,57,115,70,242,84,178,236,46,93,186,136,38,77,204,91,126,96,42,30,128,104,31,196,205,143,144,94,154,161,74,185,202,58,89,175,
  215,84,6,236,202,254,46,137,27,173,77,194,198,102,10,41,145,41,161,166,160,132,16,143,31,63,150,239,25,88,69,241,98,16,115,51,52,0,155,180,170,247,141,28,34,97,91,175,23,206,12,124,241,226,197,38,76,148,
  36,222,110,72,181,1,150,157,54,123,4,229,153,145,8,50,185,193,103,109,222,207,50,133,23,249,29,45,206,150,52,21,103,171,208,160,152,124,241,160,222,65,149,37,48,150,15,51,189,198,22,8,203,62,42,225,136,
  176,38,165,235,208,82,36,247,221,187,119,183,167,219,36,93,69,89,156,23,123,115,111,222,188,145,76,152,193,107,239,6,40,72,140,85,65,85,94,105,236,225,168,54,139,35,66,87,160,43,113,81,91,27,176,84,220,
  210,226,164,36,124,139,192,130,133,115,170,58,217,94,33,215,98,75,212,69,5,155,35,65,204,174,128,106,234,58,170,184,169,112,156,115,112,62,162,145,163,66,178,200,222,70,6,44,16,224,104,27,137,190,205,
  64,165,162,252,159,69,41,99,196,30,197,77,133,85,155,66,178,242,144,127,178,93,118,192,23,1,93,28,38,67,236,203,240,13,20,221,0,217,212,33,197,77,243,0,91,46,116,41,198,4,231,116,68,192,144,11,73,215,
  53,246,49,113,61,65,226,240,181,85,125,43,73,79,79,47,101,113,85,189,51,49,5,5,5,149,185,1,42,207,141,147,150,27,10,18,190,45,113,248,20,114,114,114,110,0,158,127,105,193,161,60,253,29,178,245,11,208,
  106,103,226,182,181,46,205,161,67,135,248,102,203,170,197,57,206,134,60,81,134,167,195,123,104,89,110,84,197,12,221,77,253,166,98,1,232,34,91,75,229,201,230,64,212,12,20,185,254,168,97,26,104,6,94,146,
  205,134,47,172,177,31,137,207,217,114,82,6,29,255,26,128,117,3,255,100,192,210,210,252,206,63,62,48,180,191,101,50,163,175,211,210,5,5,5,106,81,9,227,236,212,49,25,90,190,199,116,68,8,171,177,177,177,
  238,73,73,73,127,196,156,111,141,176,196,142,53,232,110,232,144,33,67,142,195,58,154,233,137,80,1,203,119,89,54,208,66,194,164,163,80,233,72,145,13,72,174,131,68,217,31,181,205,229,82,44,150,213,20,59,
  227,160,12,25,254,254,254,108,219,255,95,49,89,156,248,145,248,248,248,206,208,209,23,113,148,167,91,79,176,181,207,183,131,113,113,113,147,102,207,158,189,33,44,44,172,74,69,52,87,190,69,224,9,63,45,
  93,186,244,15,112,249,196,53,107,214,12,182,187,178,227,43,4,94,8,158,9,40,21,163,225,78,85,217,51,255,111,41,206,150,21,16,239,20,44,223,99,211,166,77,27,241,57,168,220,53,54,95,85,240,202,205,205,173,
  1,130,183,235,194,133,11,61,3,3,3,75,192,50,61,202,131,42,101,5,44,128,224,242,238,221,187,187,195,181,79,35,120,39,193,242,121,21,214,237,224,43,17,211,106,138,47,24,162,162,162,254,150,150,150,246,123,
  192,109,118,195,134,13,157,17,116,222,36,101,246,36,41,24,32,51,59,59,251,53,72,164,235,157,59,119,90,162,110,248,199,252,249,243,151,2,253,206,89,254,201,70,89,242,31,12,97,188,28,94,18,23,150,0,0,0,
  0,73,69,78,68,174,66,96,130,0,0};

const char* Mcfx_gain_delayAudioProcessorEditor::phase_symbol_png = (const char*) resource_Mcfx_gain_delayAudioProcessorEditor_phase_symbol_png;
const int Mcfx_gain_delayAudioProcessorEditor::phase_symbol_pngSize = 2992;

// JUCER_RESOURCE: phase_symbol_inv_png, 3151, "phase_symbol_inv.png"
static const unsigned char resource_Mcfx_gain_delayAudioProcessorEditor_phase_symbol_inv_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,49,0,0,0,49,8,6,0,0,1,4,155,113,138,0,0,0,9,112,72,
  89,115,0,0,14,197,0,0,14,197,1,71,108,236,255,0,0,12,1,73,68,65,84,120,218,197,25,9,84,20,87,242,207,208,40,32,199,112,171,81,80,140,184,236,170,81,227,241,240,6,33,32,162,114,131,241,68,204,91,143,232,
  122,189,96,212,85,115,163,49,234,186,193,213,136,226,17,15,16,24,2,94,171,128,183,137,65,68,195,102,61,48,178,18,5,69,192,225,112,112,24,152,222,170,79,55,105,198,233,97,102,100,179,245,222,135,158,254,
  255,215,245,171,234,87,85,51,44,203,18,30,226,134,12,189,190,231,198,245,161,252,111,6,255,236,149,48,108,111,34,37,51,224,249,156,164,19,93,237,195,54,74,232,36,78,32,68,17,53,57,76,204,233,175,234,234,
  106,7,6,81,205,224,38,170,120,84,0,127,246,241,205,99,144,6,162,90,73,204,200,112,216,19,2,139,50,97,247,216,121,113,123,248,133,116,2,1,39,16,22,47,94,252,119,134,39,142,52,16,21,238,192,9,202,45,47,
  202,191,228,153,33,183,75,74,122,71,46,95,182,181,85,12,158,117,39,124,94,17,191,133,138,192,191,244,5,6,36,28,221,92,120,215,202,68,30,16,191,65,52,100,8,199,12,157,152,0,171,241,231,120,216,211,58,129,
  248,114,57,116,173,250,187,152,59,182,149,101,59,27,155,58,23,39,167,202,98,224,172,13,187,8,14,18,9,155,206,9,42,132,19,164,153,108,102,155,37,109,78,132,95,172,107,3,194,36,80,43,74,86,75,88,50,149,
  85,75,24,84,136,112,49,10,144,203,253,110,128,69,147,72,19,149,20,193,22,132,66,86,25,212,160,147,0,43,50,235,7,27,115,96,161,37,44,242,109,213,88,11,160,108,12,170,124,229,138,149,91,144,5,94,127,66,
  88,219,106,8,45,128,202,160,111,120,33,191,147,152,179,182,90,152,133,234,28,51,102,204,165,87,180,199,195,154,192,160,147,202,70,85,231,173,121,185,19,94,217,204,63,220,79,75,15,47,141,156,150,38,161,
  242,180,0,111,7,27,71,14,187,122,250,202,149,81,173,27,214,13,28,92,232,83,244,243,32,221,12,17,18,127,53,127,164,204,202,74,169,80,42,173,90,78,26,22,147,118,64,222,208,100,121,254,252,249,241,76,23,
  56,200,227,2,13,69,128,122,95,194,255,38,24,106,24,199,129,137,201,240,11,85,174,240,241,63,199,8,23,87,195,137,236,133,5,188,182,240,80,67,185,197,8,118,240,190,141,178,163,184,73,60,241,96,120,70,11,
  240,165,116,116,104,9,97,6,96,64,172,155,225,48,121,115,177,212,86,235,135,128,233,11,216,135,60,127,11,152,89,206,84,52,48,2,97,243,25,45,11,96,126,96,53,18,222,58,115,180,38,181,23,175,28,50,224,6,101,
  41,204,202,92,153,161,84,91,233,83,235,253,9,227,207,22,228,156,121,135,110,120,254,226,69,151,110,46,46,21,135,159,41,156,117,45,222,62,97,108,174,28,22,183,17,186,188,162,194,5,255,7,7,7,31,87,130,101,
  90,154,119,106,44,172,120,234,90,86,86,214,221,71,40,131,46,227,227,97,119,100,116,202,210,180,212,168,56,136,12,161,156,27,8,225,17,200,157,8,110,205,246,234,85,114,173,228,129,135,24,30,70,251,5,218,
  34,91,244,211,32,95,64,250,38,181,14,115,81,38,122,192,209,225,169,144,255,60,234,205,27,55,234,16,213,34,234,21,251,35,163,210,124,41,199,102,196,84,192,67,66,130,239,58,203,158,241,234,100,120,181,244,
  73,147,71,249,234,65,142,38,189,22,44,169,24,158,145,205,16,144,98,142,150,34,214,193,252,66,192,209,21,230,240,112,93,100,50,69,133,66,33,163,171,138,210,210,162,222,20,33,16,12,198,168,164,247,9,67,
  118,104,169,110,38,204,61,134,255,232,73,54,130,59,135,135,148,26,165,29,26,5,131,17,38,84,132,192,2,206,151,180,99,222,74,120,95,200,33,70,87,90,9,135,159,41,114,118,104,117,12,134,48,49,21,149,115,225,
  1,97,5,32,190,169,131,99,13,253,219,44,170,102,52,107,6,99,228,65,8,182,61,116,4,219,62,48,144,99,127,32,112,86,132,83,188,10,34,136,68,148,8,250,13,61,147,175,123,245,44,73,0,51,228,39,230,192,70,133,
  22,199,147,224,93,131,96,51,250,121,16,32,207,211,99,226,167,2,253,78,149,157,58,25,68,137,160,35,5,142,26,117,5,227,49,254,222,167,243,46,53,55,202,148,105,136,0,2,109,252,132,191,29,36,16,186,243,140,
  68,40,132,138,0,255,147,54,75,22,37,202,131,130,78,138,122,60,132,25,170,96,188,44,162,66,66,50,191,169,121,97,103,167,71,231,188,90,114,65,247,5,5,5,111,235,12,43,250,98,23,15,205,112,157,125,27,191,
  42,161,224,198,141,33,47,212,106,115,55,15,143,7,51,214,175,251,184,143,151,215,237,246,246,50,98,19,234,154,26,187,161,221,186,151,217,52,52,88,205,7,63,112,3,73,220,248,201,252,194,225,165,41,233,49,
  91,193,108,147,165,68,147,114,236,88,100,112,88,88,134,193,4,188,187,216,214,141,83,190,176,222,70,157,83,148,7,18,14,243,225,26,34,213,132,199,164,219,51,108,211,47,79,159,186,58,56,56,84,139,18,96,65,
  124,89,167,78,141,45,230,106,120,96,196,180,48,163,73,194,108,116,116,174,242,220,189,235,189,184,121,243,146,116,18,144,2,242,215,177,164,64,96,234,222,123,243,119,39,155,153,53,199,198,198,38,183,33,
  224,248,154,102,202,131,39,200,115,106,238,252,111,20,161,161,114,25,68,92,74,96,127,244,180,35,7,244,232,218,88,152,72,88,198,163,103,207,95,171,235,234,108,40,214,85,169,71,99,14,183,195,253,94,8,135,
  89,112,111,212,194,179,23,140,207,129,33,161,143,96,182,147,1,33,113,58,119,118,169,245,42,235,220,220,220,9,204,189,244,140,176,36,61,220,191,132,141,65,128,92,202,233,211,1,198,67,24,152,99,217,114,
  241,139,15,237,152,242,241,4,240,239,148,41,83,178,152,25,177,115,247,110,20,241,86,13,13,112,77,212,254,181,99,149,2,8,135,193,28,95,148,124,9,40,249,50,131,135,185,50,167,42,166,184,174,198,142,136,
  214,0,106,202,181,174,64,248,41,32,151,112,105,154,92,144,65,10,33,164,172,188,39,51,80,79,172,81,193,72,212,242,7,62,179,36,28,215,235,192,155,241,190,222,38,194,36,227,32,130,92,195,253,247,18,136,173,
  235,182,99,128,192,29,125,177,232,133,30,239,212,197,53,222,207,131,5,179,245,48,236,245,17,40,33,226,209,212,2,198,52,224,186,66,36,171,224,171,170,48,173,195,109,67,224,25,132,7,210,200,118,210,158,
  64,174,95,82,51,37,228,43,45,174,91,15,145,203,72,166,137,196,173,114,207,126,63,51,203,230,198,237,33,59,147,22,8,39,120,93,219,114,217,198,10,208,243,59,112,42,241,160,113,52,137,124,120,94,131,57,44,
  60,159,213,227,160,59,109,45,26,152,245,255,216,177,112,209,206,93,11,34,56,46,114,96,99,177,150,174,183,1,153,179,128,238,140,160,30,177,106,39,199,165,42,182,183,127,78,93,56,167,171,203,147,136,39,
  85,93,91,82,19,51,58,132,176,20,56,95,106,100,60,186,48,121,98,214,153,172,239,166,82,2,119,203,203,187,5,74,152,230,120,34,149,118,68,176,147,144,206,202,127,91,116,86,181,9,215,203,78,159,8,186,23,56,
  233,180,39,121,125,26,97,246,230,170,234,212,212,168,54,4,2,2,2,254,153,122,244,80,204,173,152,233,71,223,122,13,34,33,182,150,181,53,213,213,14,58,111,180,168,232,232,148,28,71,199,170,77,225,81,169,
  31,212,214,219,27,131,88,237,214,251,222,60,182,193,178,166,180,212,77,239,165,239,231,231,151,227,87,83,237,48,112,192,128,162,177,143,43,92,195,159,63,119,214,135,88,245,134,251,47,179,213,181,54,242,
  35,201,177,165,35,71,94,53,56,109,249,169,168,104,0,53,209,109,219,150,38,36,36,172,178,97,204,213,158,112,5,90,129,99,86,67,130,246,227,253,226,190,62,62,62,231,14,30,60,56,243,169,157,93,141,168,39,
  27,146,120,233,3,188,176,118,37,108,140,191,116,247,110,191,187,16,250,165,92,55,171,59,218,18,87,49,105,104,100,104,137,10,229,224,79,149,24,98,128,209,254,93,187,149,251,67,170,185,240,227,143,214,59,
  59,59,63,51,149,7,163,46,123,182,177,177,211,129,153,179,247,175,135,100,78,197,54,155,69,130,193,5,192,8,6,134,131,233,10,35,18,19,12,129,165,101,238,24,169,126,216,185,123,193,105,16,53,77,66,52,50,
  87,151,138,196,125,251,230,248,129,97,119,168,16,123,194,35,143,125,144,145,22,225,13,204,46,128,96,146,76,189,165,67,92,159,130,53,224,197,136,24,193,2,82,8,92,245,129,193,167,3,9,171,185,105,107,93,
  183,63,53,37,58,160,29,129,68,133,192,132,245,211,254,111,221,218,124,239,182,215,22,32,144,214,1,233,159,49,66,197,19,137,148,212,42,237,110,66,28,11,132,80,127,44,37,37,58,34,42,42,213,96,33,80,243,
  203,65,243,95,0,243,153,191,35,243,186,96,16,28,78,30,140,226,232,119,83,28,226,226,246,164,202,229,161,24,121,196,203,5,176,249,145,246,78,85,142,202,122,235,255,55,243,218,208,23,4,73,135,244,23,227,
  242,246,113,163,47,103,101,101,77,121,69,8,172,210,250,218,59,86,197,176,172,89,64,7,38,247,26,29,153,151,161,80,9,145,204,73,43,23,197,139,229,120,246,133,241,24,255,249,16,221,202,45,150,153,83,168,
  0,166,117,178,154,105,2,219,68,46,112,217,157,74,79,134,215,210,123,149,64,142,244,170,178,46,1,166,141,32,186,148,246,99,9,153,15,79,163,180,120,10,38,13,54,42,184,192,124,125,125,243,0,124,41,150,21,
  195,70,92,195,58,57,212,132,19,80,113,153,159,154,211,54,146,11,0,6,49,244,122,105,233,191,8,152,59,75,7,75,78,208,161,166,121,215,114,88,183,5,222,55,112,77,49,84,195,40,120,250,136,75,0,117,150,214,
  112,3,23,62,120,224,129,23,37,131,29,132,164,235,63,14,79,52,65,128,4,208,252,25,78,243,174,48,142,180,227,71,3,128,89,28,203,57,141,111,0,198,149,180,206,105,49,186,209,192,242,58,224,195,80,78,98,31,
  62,115,93,11,55,61,131,45,16,236,96,190,209,78,207,69,87,77,138,166,131,186,158,12,123,255,98,0,105,222,84,120,141,35,116,227,26,126,216,116,239,167,221,206,111,7,250,16,181,5,164,42,149,12,246,112,122,
  27,41,0,2,22,213,104,74,88,121,232,19,64,200,184,148,51,21,212,248,95,57,141,243,223,141,26,104,5,244,91,33,110,112,235,1,219,13,216,132,178,52,33,226,212,182,94,76,237,51,174,209,98,188,109,182,222,130,
  163,14,70,141,9,1,5,147,69,6,187,104,197,249,249,195,141,217,40,229,218,26,183,185,164,14,29,246,57,232,116,147,129,140,11,1,171,182,102,78,152,254,38,8,129,217,46,131,109,192,109,41,71,99,140,221,140,
  125,153,72,240,11,37,53,167,102,157,166,98,200,61,240,33,87,118,90,80,7,55,46,184,152,17,11,37,166,235,12,246,49,255,228,230,254,48,189,244,87,247,112,3,236,241,2,16,253,82,160,113,161,137,57,80,129,204,
  218,101,5,153,95,4,10,224,115,111,76,221,83,77,200,16,178,71,13,42,240,113,224,90,112,242,235,249,195,122,117,237,250,36,64,195,74,173,117,56,57,22,239,139,193,249,238,9,76,101,12,172,91,203,105,28,231,
  103,195,252,19,130,95,31,91,218,66,150,92,13,97,35,232,129,88,112,239,120,232,142,237,63,96,222,148,235,85,213,221,237,193,206,91,133,131,31,61,122,212,131,10,129,5,9,54,124,227,34,34,143,29,102,205,94,
  169,175,171,64,115,35,128,181,94,180,19,241,170,169,224,239,67,156,38,241,171,98,54,136,137,182,254,152,115,88,194,53,113,122,194,24,6,106,152,10,195,202,132,136,248,27,200,42,103,55,213,89,103,103,103,
  79,182,131,138,175,149,31,236,88,31,58,117,50,40,34,56,248,248,129,38,194,8,79,196,85,199,183,44,49,192,134,28,134,201,233,175,241,33,174,189,34,59,186,182,194,229,132,252,196,164,145,92,45,220,134,51,
  172,166,176,51,254,199,222,30,15,102,215,214,217,5,254,143,24,49,21,174,78,157,148,185,235,70,193,219,15,31,62,116,183,181,181,173,21,173,39,176,181,255,164,70,33,219,147,148,52,47,228,253,247,191,222,
  164,106,234,236,217,129,85,156,41,240,216,123,196,229,153,223,95,30,125,36,38,58,165,52,83,30,106,112,101,135,159,16,112,36,39,39,199,134,47,89,178,125,94,125,163,5,246,204,127,47,198,177,101,117,101,
  170,223,153,175,46,94,24,183,99,201,162,68,246,234,165,49,38,215,216,248,169,2,135,66,161,144,205,154,53,235,192,229,115,231,124,98,235,165,236,68,72,135,59,222,216,100,149,23,38,123,95,253,219,165,139,
  99,253,253,253,207,38,129,53,172,17,152,205,107,119,59,240,147,136,176,154,194,15,12,159,124,246,217,154,252,107,215,70,12,132,232,54,84,205,74,7,148,85,58,99,82,102,200,37,245,200,211,189,164,208,217,
  190,250,154,170,193,178,240,206,157,63,120,123,123,127,191,122,245,234,207,55,140,31,127,126,131,145,162,255,23,237,116,195,102,163,205,170,254,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* Mcfx_gain_delayAudioProcessorEditor::phase_symbol_inv_png = (const char*) resource_Mcfx_gain_delayAudioProcessorEditor_phase_symbol_inv_png;
const int Mcfx_gain_delayAudioProcessorEditor::phase_symbol_inv_pngSize = 3151;

// JUCER_RESOURCE: phase_symbol_over_png, 3018, "phase_symbol_over.png"
static const unsigned char resource_Mcfx_gain_delayAudioProcessorEditor_phase_symbol_over_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,49,0,0,0,49,8,6,0,0,1,4,155,113,138,0,0,0,9,112,
  72,89,115,0,0,14,197,0,0,14,197,1,71,108,236,255,0,0,11,124,73,68,65,84,120,218,205,89,7,80,84,235,21,254,193,139,60,16,4,81,196,174,160,177,141,142,138,134,40,70,99,23,137,81,95,84,4,123,111,232,24,176,
  151,49,51,168,216,198,130,117,198,8,138,58,40,118,159,141,103,175,56,177,98,155,216,11,96,5,236,162,162,178,249,190,63,123,215,187,203,238,178,11,228,37,103,230,194,238,254,237,156,243,159,243,157,114,
  21,157,78,39,84,138,140,140,188,184,120,241,226,38,234,119,133,127,110,220,184,161,171,87,175,158,192,0,191,170,179,29,228,32,7,72,21,42,84,16,143,31,63,22,142,142,142,226,237,219,183,94,138,126,43,57,
  240,226,197,11,225,228,228,36,39,142,31,63,254,152,162,63,67,23,23,23,39,130,130,130,68,169,82,165,196,235,215,175,133,191,191,127,172,162,30,206,1,18,7,72,99,199,142,93,174,14,58,188,122,245,202,139,
  91,113,5,7,36,183,170,40,143,30,61,234,6,174,125,59,119,238,188,196,32,6,207,171,86,173,154,224,3,90,172,138,32,151,144,109,7,7,7,57,235,251,247,239,58,3,19,185,185,185,226,232,209,163,162,109,219,182,
  63,52,82,172,88,49,185,162,103,207,158,70,3,14,92,42,52,116,250,244,233,150,6,150,61,60,60,222,151,43,87,46,243,246,237,219,190,45,90,180,248,193,46,169,108,217,178,186,151,47,95,10,83,90,179,102,141,
  24,62,124,184,131,209,141,168,147,205,45,32,97,129,20,23,74,18,94,94,94,14,10,21,162,157,76,230,41,25,233,253,251,247,162,100,201,146,66,229,6,11,4,89,85,168,65,189,178,12,68,201,33,164,112,119,119,23,
  97,97,97,70,99,148,77,161,202,193,243,98,61,11,134,83,84,74,72,72,48,250,78,101,40,122,158,165,144,224,89,71,22,204,17,213,9,205,157,54,186,108,45,45,92,184,240,0,228,113,142,138,138,106,107,58,102,184,
  210,140,140,140,238,101,202,148,217,206,251,158,56,113,162,250,179,220,13,236,39,239,219,183,175,185,97,193,170,85,171,174,140,30,61,186,161,176,64,152,28,8,118,179,193,182,171,92,96,109,178,74,152,236,
  114,226,196,137,86,10,212,168,163,254,53,42,148,247,65,21,231,228,228,24,238,134,223,225,105,199,21,237,228,231,207,159,139,155,55,111,138,210,165,75,27,238,6,114,201,201,36,126,86,180,199,86,170,84,73,
  124,251,246,77,238,234,233,233,41,39,170,70,159,71,75,164,169,83,167,202,93,15,31,62,108,216,213,213,213,213,120,65,167,78,157,196,193,131,7,197,215,175,95,69,116,116,180,188,113,62,92,80,162,68,9,241,
  249,243,103,227,5,152,204,51,117,89,89,89,134,93,85,50,157,220,184,113,227,203,146,37,8,153,141,5,174,214,212,138,141,15,95,186,116,169,131,92,128,201,37,42,86,172,248,242,201,147,39,222,230,38,195,119,
  143,110,219,182,173,131,145,208,152,92,86,111,6,251,32,131,175,139,139,75,206,185,115,231,124,158,62,125,90,1,147,127,200,96,206,248,84,218,189,123,119,98,191,126,253,66,168,12,64,83,158,241,59,119,238,
  136,113,227,198,137,15,31,62,60,132,69,251,89,218,71,49,253,129,182,136,123,107,216,187,119,111,209,173,91,55,161,53,6,83,170,89,179,166,188,21,144,175,106,220,122,29,150,176,232,21,184,231,237,176,95,
  81,24,210,95,146,14,186,207,80,213,169,168,106,233,218,181,107,8,185,183,68,52,105,232,94,92,189,122,85,66,76,120,120,184,152,53,107,150,209,28,74,190,116,233,82,137,227,188,92,248,204,27,172,243,148,
  135,164,165,165,133,152,154,180,74,116,36,170,44,51,51,83,92,188,120,209,104,172,122,245,234,226,193,131,7,18,24,57,79,141,57,26,198,60,104,20,10,17,70,3,26,70,212,164,73,19,105,208,166,198,209,166,77,
  27,113,242,228,73,185,49,93,169,67,135,14,121,14,208,196,27,95,122,185,179,37,21,145,75,213,107,90,183,110,45,78,157,58,149,135,99,115,76,104,137,102,173,16,35,97,138,58,90,138,41,53,104,208,64,0,160,
  100,208,166,95,155,53,79,69,145,102,108,137,232,55,242,78,134,12,25,66,59,247,85,7,106,215,174,45,51,2,45,199,4,138,79,159,62,25,184,38,202,12,27,54,204,170,20,179,103,207,62,8,199,12,86,244,161,193,15,
  23,116,150,120,204,239,183,110,221,202,179,224,227,199,143,118,153,178,30,34,130,141,252,68,141,14,176,50,157,53,238,242,163,228,228,228,3,111,222,188,89,137,3,14,88,244,120,28,32,109,153,193,34,52,52,
  116,55,66,178,7,97,221,26,81,45,187,118,237,242,1,18,54,14,12,12,204,123,111,54,114,237,186,103,207,158,121,240,19,127,224,148,19,188,249,65,143,30,61,162,224,116,255,202,111,161,98,105,0,7,123,52,111,
  222,252,41,112,200,117,201,146,37,2,104,32,31,61,5,224,9,141,137,137,17,51,102,204,200,77,76,76,236,25,28,28,188,211,230,3,58,118,236,248,30,42,114,131,94,173,114,71,147,197,227,8,31,217,1,85,126,131,
  11,248,32,128,191,178,118,128,19,56,206,97,184,178,135,24,56,1,53,10,114,92,46,28,54,120,240,224,181,102,15,128,37,229,20,198,146,176,49,241,236,31,235,214,173,251,62,104,208,160,117,70,7,248,248,248,
  20,202,76,181,216,150,146,146,178,6,38,187,11,49,232,141,162,15,184,155,239,222,189,43,138,138,134,14,29,170,64,213,105,80,181,187,60,96,228,200,145,161,172,42,172,209,244,233,211,197,234,213,171,37,156,
  4,4,4,136,253,251,247,11,173,143,208,235,105,85,211,166,77,147,223,1,61,110,200,232,219,42,192,244,191,94,191,126,221,226,198,217,217,217,194,205,205,77,166,72,4,66,168,82,230,91,200,190,101,250,196,236,
  90,133,246,150,45,91,26,14,32,48,34,72,253,162,244,233,211,39,142,181,131,57,82,179,35,162,47,114,96,163,49,132,98,121,8,15,102,64,58,116,232,144,161,204,208,72,157,165,92,187,118,205,195,18,247,228,220,
  217,217,57,207,230,164,94,189,122,25,74,0,30,102,46,223,158,50,101,74,101,133,101,138,37,98,170,6,140,55,250,77,205,44,73,228,154,222,221,165,75,23,113,230,204,25,243,80,81,190,124,121,139,234,33,53,109,
  218,212,240,155,185,104,71,9,1,116,150,177,8,181,168,69,239,52,199,53,227,51,47,85,37,216,187,188,11,139,7,88,179,32,70,177,202,149,43,11,68,41,179,89,133,22,147,44,30,144,158,158,158,131,255,197,77,7,
  200,53,67,38,198,101,133,170,229,90,37,150,6,244,126,92,166,217,205,47,95,190,124,83,153,52,105,82,44,62,143,210,14,168,186,70,33,40,75,6,154,31,114,90,17,31,31,47,205,50,41,41,73,94,46,239,201,82,130,
  160,175,246,63,41,147,39,79,30,13,188,31,21,17,17,33,127,220,180,105,19,79,54,210,245,168,81,163,196,134,13,27,196,198,141,27,85,80,100,154,34,190,124,249,98,213,251,225,152,175,37,84,172,93,187,246,57,
  14,40,199,207,125,251,246,149,143,150,8,17,124,236,33,48,253,11,204,184,171,60,0,174,95,190,127,255,254,223,193,165,99,17,225,93,54,252,231,11,181,98,128,107,64,70,48,176,60,137,112,91,88,130,87,127,1,
  70,133,24,197,3,132,201,95,183,111,223,30,138,160,190,165,85,171,86,5,222,28,254,242,14,190,225,101,54,162,33,83,72,60,114,228,72,22,238,96,43,46,187,148,61,27,3,143,238,160,234,115,193,230,85,172,6,253,
  118,237,218,29,193,227,133,92,245,122,88,88,152,15,108,220,219,218,198,192,253,251,152,235,190,115,231,206,65,169,169,169,201,54,167,45,40,70,234,243,63,138,142,191,205,155,55,111,10,68,255,138,98,252,
  13,16,54,7,49,196,1,25,199,239,160,202,227,48,221,126,248,254,214,162,39,23,54,14,51,96,197,198,198,78,62,118,236,88,173,43,87,174,120,16,195,144,152,9,63,63,63,25,75,8,49,132,116,34,3,163,30,75,5,84,
  72,68,128,28,127,127,255,103,208,214,1,36,11,127,247,246,246,206,40,40,15,138,157,243,139,35,71,136,135,137,247,4,84,21,155,48,97,130,24,48,96,128,12,217,124,236,221,11,79,85,98,5,108,99,20,19,200,69,
  139,22,229,2,161,94,46,91,182,108,32,16,234,215,34,21,2,137,254,54,148,46,61,24,191,112,144,217,138,162,48,196,136,67,223,199,67,60,41,7,161,146,128,47,185,112,156,247,72,229,122,209,83,11,42,132,211,
  250,245,235,175,70,70,70,214,97,17,199,90,235,183,34,10,165,7,72,143,227,199,143,39,17,198,1,55,189,186,119,239,190,213,102,33,168,121,152,73,15,102,114,76,178,254,151,196,64,72,191,69,188,74,68,52,141,
  69,93,242,51,145,199,154,16,197,113,117,89,85,170,84,113,179,183,100,248,111,19,64,128,253,25,55,226,242,242,229,203,207,160,194,235,146,71,8,86,105,117,234,212,201,66,212,46,134,114,162,200,14,87,83,
  58,109,230,101,43,17,197,136,116,90,98,96,89,185,114,101,43,226,191,10,209,6,33,88,102,134,135,135,23,88,0,230,60,92,187,99,199,14,249,157,137,150,165,12,143,196,94,56,50,144,60,227,92,63,112,224,64,41,
  52,147,49,2,9,27,88,90,2,159,238,128,108,31,164,66,64,246,99,109,164,16,115,230,204,249,39,235,100,115,13,196,252,136,153,57,223,168,48,49,83,95,85,80,24,160,139,81,66,173,239,155,200,156,139,15,98,139,
  124,24,75,40,12,27,48,44,130,232,196,244,1,34,33,162,167,176,212,96,99,4,70,78,231,199,64,73,33,92,33,109,192,249,243,231,237,22,128,153,38,147,68,181,105,157,150,150,102,117,62,203,20,62,124,89,66,141,
  135,132,132,200,0,200,91,33,179,204,84,225,184,162,120,241,226,54,157,15,190,125,130,130,130,166,40,108,129,192,145,69,141,26,53,236,18,128,193,141,140,80,243,35,70,140,96,231,54,223,53,170,169,168,26,
  39,177,199,201,250,151,153,48,83,66,91,5,32,53,108,216,240,39,192,113,166,194,30,78,253,250,245,237,190,5,102,203,180,123,214,88,214,4,48,101,92,53,21,85,227,252,206,154,152,227,43,86,172,176,59,242,51,
  215,82,216,132,98,73,107,47,226,168,37,151,90,223,217,195,184,73,147,70,230,87,172,7,11,18,147,152,44,42,236,162,157,61,123,54,192,222,54,18,219,26,244,35,40,65,58,44,35,58,29,218,22,198,181,196,170,141,
  160,192,53,166,64,96,99,2,234,160,176,13,136,52,56,212,222,197,140,230,116,102,58,38,219,37,20,204,86,198,181,113,128,239,7,184,142,62,177,119,239,94,187,107,46,166,235,10,251,152,141,26,53,122,28,19,
  19,83,213,90,245,173,210,214,173,91,217,199,54,114,78,254,167,137,177,61,64,255,200,79,0,50,207,155,100,55,128,196,222,135,250,217,30,138,142,142,190,132,122,227,63,45,184,132,132,132,223,35,255,127,142,
  124,201,209,156,141,243,186,121,213,41,41,41,6,83,33,28,110,217,178,69,50,204,113,246,160,136,50,140,176,106,221,77,199,231,126,106,61,193,223,40,188,74,190,190,190,242,69,22,29,219,94,130,249,62,152,
  59,119,110,163,244,244,244,74,114,53,11,18,54,124,225,233,219,192,136,163,105,138,240,236,217,51,17,28,28,44,136,98,196,120,83,77,179,59,247,240,225,67,249,153,206,73,228,226,203,175,251,247,239,75,135,
  165,208,56,67,10,202,215,149,124,199,69,103,46,40,229,228,228,100,34,237,112,131,249,253,5,245,199,91,131,10,216,177,142,143,143,15,246,241,241,217,119,239,222,61,69,123,35,140,35,166,239,178,172,148,
  238,5,45,146,108,46,178,107,213,170,85,22,153,246,159,3,3,3,147,243,100,177,172,166,216,25,175,91,183,238,131,217,179,103,123,176,199,252,255,68,136,35,187,23,44,88,208,248,209,163,71,85,113,147,239,44,
  214,19,108,237,195,201,60,227,226,226,134,226,54,86,160,186,114,46,138,230,74,97,232,12,8,233,202,31,55,111,222,156,152,154,154,250,179,205,149,29,95,33,240,65,121,56,8,53,198,178,249,243,231,255,196,
  158,249,111,200,123,54,52,127,104,230,204,153,127,2,226,173,132,95,181,40,112,141,205,87,21,124,224,160,158,64,164,13,80,74,235,168,168,40,29,242,37,247,130,160,74,126,14,139,90,33,25,254,215,18,213,219,
  97,100,183,67,199,140,25,243,174,200,186,29,124,37,162,173,166,248,130,1,41,252,244,11,23,46,252,1,152,159,209,190,125,123,71,100,148,222,76,202,108,209,50,202,205,135,136,214,175,144,78,187,32,127,171,
  221,172,89,179,115,211,166,77,139,142,136,136,56,161,182,81,109,165,127,3,18,33,62,210,0,40,7,24,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* Mcfx_gain_delayAudioProcessorEditor::phase_symbol_over_png = (const char*) resource_Mcfx_gain_delayAudioProcessorEditor_phase_symbol_over_png;
const int Mcfx_gain_delayAudioProcessorEditor::phase_symbol_over_pngSize = 3018;

//[EndFile] You can add extra defines here...
//[/EndFile]
