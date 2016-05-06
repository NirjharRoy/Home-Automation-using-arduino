package com.example.abc;

import org.junit.Test;
import org.junit.Rule;
import org.junit.runner.RunWith;

import android.support.test.espresso.assertion.ViewAssertions;
import android.support.test.rule.ActivityTestRule;


import static org.junit.Assert.*;
import static android.support.test.espresso.Espresso.onView;
import static android.support.test.espresso.matcher.ViewMatchers.isDisplayed;
import static android.support.test.espresso.matcher.ViewMatchers.withText;

/**
 * Created by Anindya on 04-05-2016.
 */
public class MainActivityTest {

    @Rule
    public ActivityTestRule<MainActivity> mActivityRule = new ActivityTestRule(MainActivity.class);

    @Test
    public void shouldBeAbleToLaunchMainScreen(){
        onView(withText("Light State")).check(ViewAssertions.matches(isDisplayed()));
    }



    @Test
    public void testOnCreate() throws Exception {
        onView(withText("Fan Speed")).check(ViewAssertions.matches(isDisplayed()));

    }

    @Test
    public void testClick() throws Exception {
        onView(withText("Off")).check(ViewAssertions.matches(isDisplayed()));

    }

    @Test
    public void testMsgSend() throws Exception {

        try{

        }
        catch(Exception e){
            assertTrue(false);

        }
    }

    @Test
    public void testRclk() throws Exception {

        onView(withText("Set")).check(ViewAssertions.matches(isDisplayed()));
    }

}