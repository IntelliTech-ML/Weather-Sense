# ☁️ Weather Condition Classifier ☀️

Predict the weather with a simple, easy-to-use Windows application! This project uses a machine learning model to analyze temperature, humidity, wind speed, and pressure to determine the current weather condition.

---

## ✨ Introduction

Ever wonder if you'll need an umbrella or sunglasses today? ☔😎 This **Weather Condition Classifier** harnesses the power of machine learning to bring you accurate weather predictions right to your desktop! It's a fantastic demonstration of how cutting-edge machine learning can be seamlessly integrated with a user-friendly interface. Perfect for tech enthusiasts and anyone curious about bridging the gap between data science and practical applications!

---

## 🚀 Features

* 🎯 **Accurate Predictions:** Powered by a robust **Random Forest Classifier** that has been meticulously trained to deliver reliable weather forecasts.
* 🖥️ **Simple Interface:** Enjoy a straightforward and intuitive Windows application, making it super easy to input your weather data.
* 📜 **Prediction History:** Never lose track! The application keeps a handy record of your past predictions for quick and easy review.
* 🧠 **Machine Learning Powered:** Dive into the world of AI with a project that truly leverages the strength of machine learning for insightful results.
* 📚 **Educational Value:** A brilliant learning resource! This project beautifully showcases the synergy between **C data structures** and **Python machine learning**.

---

## 🛠️ Installation

Ready to get started? Follow these simple steps to set up your Weather Condition Classifier!

1.  **Grab the Code!** 🧑‍💻 Clone this repository to your local machine:

    ```bash
    git clone [https://github.com/ml-beginner-learner/weather-condition-classifier](https://github.com/ml-beginner-learner/weather-condition-classifier)
    ```

2.  **Get the Tools You Need!** 🔧

    * **Python:** Ensure you have **Python 3.x** installed. We highly recommend using a virtual environment to keep your project dependencies neat and tidy:

        ```bash
        python -m venv .venv       # Create a virtual environment
        .venv\Scripts\activate    # Activate on Windows
        source .venv/bin/activate # Activate on Linux/macOS
        pip install -r requirements.txt # Install necessary Python libraries
        ```

    * **C Compiler:** You'll need a C compiler like **GCC** or **MinGW** to build the Windows application.

3.  **Build the App!** 🏗️ Compile the C code to create your executable application:

    ```bash
    gcc main.c -o weather_classifier.exe -lcomdlg32  # Important: Add -lcomdlg32 for MessageBox
    ```

---

## 💡 How to Use

Once installed, predicting the weather is a breeze! 🌬️

1.  **Start the Engine!** 🚂 First, run the Python script to load the powerful machine learning model:

    ```bash
    python predict.py
    ```
    (No need to keep this running once the model is prepared – it just sets things up!)

2.  **Launch the App!** 🚀 Now, open your compiled Windows application:

    ```bash
    weather_classifier.exe
    ```

3.  **Enter the Data!** 📝 Input the temperature, humidity, wind speed, and pressure into the application's interface.

4.  **Get the Prediction!** 🔮 Click the "Predict" button to unveil the predicted weather condition!

5.  **Check the History!** 🕰️ Curious about your past forecasts? Click "History" to review them.

6.  **Try Again!** 🔄 Ready for a new prediction? Click "Run Again" to enter fresh data.

---

## 📂 What's Inside?

A peek into the project's structure:


Weather-Condition-Classifier/
├── label_encoder.pkl        # Helps the model understand weather labels (Sunny, Rainy, etc.)
├── main.c                   # The beating heart of the Windows app (written in C)
├── predict.py               # Python script to load and prepare the machine learning model
├── random_forest_model.pkl  # The star of the show: your trained machine learning model!
├── requirements.txt         # A comprehensive list of all required Python libraries
└── README.md                # You're reading it right now!

---

## 🔗 Dependencies

To make this project sing, you'll need:

* **Python:** Specifically, **Python 3.x**.
* **Python Libraries:** Easily install them with `pip install -r requirements.txt`. This includes essential packages like `scikit-learn`, `pickle`, and `numpy`.
* **C Compiler:** Any C compiler will do, such as **GCC**, **MinGW**, or similar.

---

## 🎯 Future Ideas

We're always looking to improve! Here are some exciting possibilities for future enhancements:

* 🎨 **More Visuals:** Let's make the user interface even more dazzling and engaging!
* 📡 **Real-Time Weather:** Imagine connecting to a live weather API for instant, up-to-the-minute data!
* 📊 **Performance Check:** Deeper analysis into the model's accuracy and performance.
* 📦 **Easy Install:** Creating a single, streamlined installer file for effortless setup.

---

## 👋 Contribute

Got an idea to make this project even better? We'd love your help! Feel free to open an issue or send a pull request. Your contributions are highly valued! ✨

