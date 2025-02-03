import sys
import pickle
import numpy as np
import pandas as pd
import os

def load_model(model_path):
    with open(model_path, 'rb') as file:
        model = pickle.load(file)
        if not hasattr(model, 'predict'):
            raise ValueError("Loaded object is not a valid model.")
    return model

def load_label_encoder(encoder_path):
    with open(encoder_path, 'rb') as file:
        encoder = pickle.load(file)
    return encoder

def main():
    if len(sys.argv) != 5:
        print("Usage: python predict.py <Temperature> <Humidity> <Air_Pressure> <Wind_Speed>")
        sys.exit(1)
    
    try:
        # Read input arguments (ensure order matches training)
        temperature = float(sys.argv[1])
        humidity = float(sys.argv[2])
        air_pressure = float(sys.argv[4])
        wind_speed = float(sys.argv[3])
        
        # Get the current directory where the script is located
        current_dir = os.path.dirname(os.path.abspath(__file__))
        
        # Load trained model and encoder from the same directory
        model_path = os.path.join(current_dir, "random_forest_model.pkl")
        encoder_path = os.path.join(current_dir, "label_encoder.pkl")
        
        model = load_model(model_path)
        encoder = load_label_encoder(encoder_path)

        # Prepare input features as a pandas DataFrame with correct feature names
        input_features = pd.DataFrame([[temperature, humidity, air_pressure, wind_speed]],
                                      columns=["Temperature", "Humidity", "Air_Pressure", "Wind_Speed"])

        # Make prediction
        encoded_prediction = model.predict(input_features)[0]

        # Decode prediction
        weather_prediction = encoder.inverse_transform([encoded_prediction])[0]

        # Print the result (C program will capture this output)
        print(weather_prediction)
    
    except ValueError as ve:
        print(f"Value Error: {ve}")
        sys.exit(1)
    except FileNotFoundError as fe:
        print(f"File Error: {fe}")
        sys.exit(1)
    except Exception as e:
        print(f"Unexpected Error: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
