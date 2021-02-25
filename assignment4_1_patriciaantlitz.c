//
//  main.c
//  assignment4_1_patriciaantlitz
//
//  Created by Patricia Antlitz on 2/23/21.
//
/*---------------------------------------------------------------------*/
     /* Student Name: Patricia Antlitz                                 */
     /* Submission Date: Feb 23, 2021                                  */
     /* Program 1: Write a program to calculate the Body Mass Index (BMI).
      The formulae to calculate the BMI are:
      BMI = (weightinPounds x 703) / (heightinInches x heightinInches ) or
      BMI = weightinKilograms / (heightinMeters x heightinMeters )
      Your program should read the user's weight in pounds and height in inches (or, Kilograms and meters, if you prefer), calculate, and display the BMI.
      Your program should also display a message indicating how the BMI is evaluated, based on the following BMI values:

      Underweight: less than 18.5
      Normal: between 18.5 and 24.9
      Overweight: between 25 and 29.9
      Obese: 30 or greater                             */
 
 /*
 *
 * Week #: 3-4
 * Problem #: 1
 * Filename: assignment4_1_patriciaantlitz.c
 *
 * Notes:
 *        -  When running this program, the user is expected to use the CLI in their machine, or withing the IDE of their preference. If using an IDE, the user can click on either "run", "play", "compile" or "build" depending on the selected IDE. The user will then be asked to enter data in the CLI. The program will calculate the user's BMI based on the data entered and how many pounds the user should lose or gain in order to have a normal BMI.
  
          -  This program used other sources:
  reverser BMI calculation:
  https://healthfully.com/convert-bmi-pounds-7377099.html
  floats/doubles into ints:
  https://www.baeldung.com/java-separate-double-into-integer-decimal-parts
 
 * Sample Output:
    
  Body Mass Index Calculator.

  Enter Your Weight in Pounds:
  174
  You Entered: 174 lbs

  Enter Your Height in Feet: (E.g., 5.7)
  5.6
  You Entered: 5'6"

  Your BMI was evaluated to:

  BMI: 28.1, Overweight - Body Mass Index is in between 25.0 and 29.9.
  You need to lose at least 37.7 lbs to have an average, 22.0 NORMAL BMI.

  Program ended with exit code: 0
 *
 */
/*-----------------------------------------------------------------------*/

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    //weigh in pounds
    int weightInLbs;
    //height in feet and inches
    float heightFeet;
    // the follwowing variables will be explaines as they are called
    float totalHeightInInch;
    float heightInInch;
    float bodyMass;
    float healthyBmiLose;
    float healthyBmiGain;
    float poundsToGain;
    float poundsToLose;
    
    //program title, explain what it is
    printf("Body Mass Index Calculator.\n\n");
    
    //asks user to enter a number as their weight in pounds
    printf("Enter Your Weight in Pounds:\n");
    //scans the user's entry and stores on variable weightInLbs
    scanf("%d", &weightInLbs);
    //reads the entry back to the user
    printf("You Entered: %d lbs\n\n", weightInLbs);
    
    //askes the user to enter a decimal value for their height in feet
    printf("Enter Your Height in Feet: (E.g., 5.7) \n");
    //scans user's entry and stores it on variable heightFeet as a decimal
    scanf("%f", &heightFeet);
    
    /* gets the value of vriable heightFeet and turns into an int, gets the value before the decimal point, stores in variable feet to allow variable heightFeet to be intact E.g., 5.7 = 5 */
    int feet = (int)heightFeet;
    /* Variable heightInInch holds the calculation that turns the number after the decimal point into a number in the 10ths allows it to be added to the height when converted to inches.
        gets the digits after the decimal point and multiply by 10 to move the decimal E.g., 0.7000~ = 7.0000~ */
    heightInInch = (heightFeet - feet) * 10;
    /* Get the value of "feet" (5) multiplies by 12 to turn into inches and adds the value of heightInInch (7.00..). 5'7" = 67inch~~ */
    totalHeightInInch = (feet * 12) + heightInInch;
    //reads to user the height entered in feet and inches format
    printf("You Entered: %d'%.0f\"\n\n", feet, heightInInch);
        //testing
//    printf("%d %f %f\n", feet, heightInInch, totalHeightInInch);
    
    // Variable bodyMass holds the calculation for the BMI
    bodyMass = (weightInLbs * 703) / (totalHeightInInch * totalHeightInInch);
    /* Variable poundsToLose takes the value of bodyMass (BMI) and subtracts the avarage normal BMI from it ( average = (18.5 + 24.9) / 2 ) to calculate the difference between the user's BMI and a healthy BMI*/
    poundsToLose = (bodyMass - 22);
    /* takes the difference between BMIs from user and healthy BMI and turns into pounds to be lost */
    healthyBmiLose = (poundsToLose / 703) * (totalHeightInInch * totalHeightInInch);
    
    /* similar to poundsToLose, calculates the difference between a healthy BMI and an underweight BMI and turns it into pounds to be gaines*/
    poundsToGain = (22 - bodyMass);
    healthyBmiGain = (poundsToGain / 703) * (totalHeightInInch * totalHeightInInch);
    // testing
//    printf("total pounds to gain %.2f\n\n", healthyBmiGain);
    //prints text to the screen to inform of the next steps in the program
    printf("Your BMI was evaluated to:\n\n");
    
    //if statement will check conditionals. If the value of bodyMass is less than 18.5
    if(bodyMass < 18.5) {
        //program will print the user's BMI as Underweight
        printf("BMI: %.1f, Underweight - Body Mass Index is less than 18.5.\n", bodyMass);
        // prints how many pounds the user should gain
        printf("You need to gain at least %.1f lbs to have an average, 22.0 NORMAL BMI.\n", healthyBmiGain);
    }
    // if bodyMass is in between 18.5 and 24.9
    else if((bodyMass > 18.5) && (bodyMass <= 24.9)){
        //program will print the user's BMI as normal
        printf("BMI: %.1f, Normal - Body Mass Index is in between 18.5 and 24.9.\n", bodyMass);
    }
    // if greater than 25 and less or equal to 29.9
    else if((bodyMass > 25) && (bodyMass <= 29.9)){
        //program will print the user's BMI as Overweight
        printf("BMI: %.1f, Overweight - Body Mass Index is in between 25.0 and 29.9.\n", bodyMass);
        // prints how many pounds the user should lose
        printf("You need to lose at least %.1f lbs to have an average, 22.0 NORMAL BMI.\n", healthyBmiLose);
    }
    //else, if greater than 30
    else{
        //program will print the user's BMI as Obese
        printf("BMI: %.1f, Obese - Body Mass Index is greater than 30.0.\n", bodyMass);
        // prints how many pounds the user should lose
        printf("You need to lose at least %.1f lbs to have an average, 22.0 NORMAL BMI.\n", healthyBmiLose);
    }
    //prints a new line
    printf("\n");
    //if successfull, return status 0
    return 0;
}

// end.
