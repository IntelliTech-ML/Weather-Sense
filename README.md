# Weather Condition Classifier

Predict the weather with a simple, easy-to-use Windows application! This project uses a machine learning model to analyze temperature, humidity, wind speed, and pressure to determine the current weather condition.

## Introduction

Want to know if it's going to rain or shine? This Weather Condition Classifier uses the power of machine learning to give you accurate predictions right from your desktop. It's a great example of how to combine machine learning with a user-friendly interface.

## Features

*   *Accurate Predictions:* Uses a trained Random Forest Classifier to predict weather conditions.
*   *Simple Interface:* Easy-to-use Windows application for inputting weather data.
*   *Prediction History:* Keeps track of your past predictions for easy review.
*   *Machine Learning Powered:* Leverages the power of machine learning for accurate results.
*   *Educational:* Demonstrates the use of data structures in C and machine learning in Python.

## Installation

1.  *Grab the Code:* Clone this repository to your computer:

    bash
    git clone [https://github.com/ml-beginner-learner/weather-condition-classifier](https://github.com/ml-beginner-learner/weather-condition-classifier)  # Replace with your repository URL
    

2.  *Get the Tools:*

    *   *Python:* Make sure you have Python 3.x installed. We recommend using a virtual environment to keep things organized:

        bash
        python -m venv .venv       # Create a virtual environment
        .venv\Scripts\activate    # Activate on Windows
        source .venv/bin/activate # Activate on Linux/macOS
        pip install -r requirements.txt # Install Python libraries
        

    *   *C Compiler:* You'll need a C compiler (like GCC or MinGW) to build the Windows application.

3.  *Build the App:* Compile the C code:

    bash
    gcc main.c -o weather_classifier.exe -lcomdlg32  # Important: Add -lcomdlg32 for MessageBox
    

## How to Use

1.  *Start the Engine:* Run the Python script first to load the machine learning model:

    bash
    python predict.py
    

    (This prepares the model; you don't need to keep it running.)

2.  *Launch the App:* Run the compiled Windows application:

    bash
    weather_classifier.exe
    

3.  *Enter the Data:* Type in the temperature, humidity, wind speed, and pressure.

4.  *Get the Prediction:* Click "Predict" to see the predicted weather condition!

5.  *Check the History:* Click "History" to see your past predictions.

6.  *Try Again:* Click "Run Again" to enter new data.

## What's Inside


Weather-Condition-Classifier/
├── label_encoder.pkl        # Helps the model understand weather labels (Sunny, Rainy, etc.)
├── main.c                   # The heart of the Windows app (C code)
├── predict.py               # Python script to load the machine learning model
├── random_forest_model.pkl  # The trained machine learning model itself
├── requirements.txt         # List of Python libraries needed
└── README.md                # This file!

## Dependencies

*   *Python:* Python 3.x
*   *Python Libraries:* Install with pip install -r requirements.txt (includes scikit-learn, pickle, numpy).
*   *C Compiler:* GCC, MinGW, or similar.

## Future Ideas

*   *More Visuals:* Make the UI even better!
*   *Real-Time Weather:* Connect to a weather API for live data.
*   *Performance Check:* See how accurate the model is.
*   *Easy Install:* Create a single installer file.

## Contribute

Want to make this project even better? Contributions are welcome! Open an issue or send a pull request.

