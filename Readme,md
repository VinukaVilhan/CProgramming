# Harveston Climate Forecasting

## Technical Report Submission for Competition

**Project Title:** Harveston Climate Forecasting  
**Team Name:** RainMakers - Data_Crunch_025  
**Institution:** University of Moratuwa  

## Overview
This project focuses on time series forecasting for key environmental variables affecting agriculture in Harveston. Our goal is to develop robust predictive models to assist farmers in decision-making regarding planting cycles, resource allocation, and weather preparedness.

## Dataset & Preprocessing
### Key Variables Forecasted:
- **Average Temperature (°C)**
- **Radiation (W/m²)**
- **Rain Amount (mm)**
- **Wind Speed (km/h)**
- **Wind Direction (°)**

### Preprocessing Steps:
- **Unit Standardization:** Converted temperature values from Kelvin to Celsius.
- **Outlier Treatment:** Applied Winsorization to cap extreme values.
- **Seasonality Analysis:** Decomposed time series to identify annual trends.
- **Feature Engineering:** Generated lagged features, cyclical encodings, and rolling statistics.
- **Scaling & Encoding:** Used Min-Max Scaling for numerical features and label encoding for categorical ones.

## Model Selection & Justification
### Implemented Models:
- **Baseline:** Seasonal Naïve, Historical Average
- **Statistical:** ARIMA, SARIMA
- **Machine Learning:** Random Forest, XGBoost
- **Deep Learning:** LSTM, CNN, Transformer-based models
- **Hybrid Approaches:** Ensemble of SARIMA, Prophet, and LSTM

### Best Performing Models per Variable:
| Variable | Best Model | RMSE |
|----------|-----------|------|
| Temperature | Ensemble (SARIMA + Prophet + LSTM) | 1.23°C |
| Radiation | Temporal Convolutional Network (TCN) | 14.7 W/m² |
| Rain Amount | Two-stage XGBoost | 3.6mm |
| Wind Speed | Gradient Boosting | 1.8km/h |
| Wind Direction | Bidirectional LSTM (sin-cos transformed) | CMAE: 18.5° |

## Performance Evaluation & Validation
### Metrics Used:
- **Primary:** RMSE, MAE, MAPE, Circular Mean Absolute Error (CMAE)
- **Secondary:** CRPS, Direction Accuracy, Precipitation F1-score
- **Validation Techniques:** Time-based validation, rolling origin forecasting, backtesting

## Key Innovations
- **Hybrid CNN-LSTM with Attention:** Captures both local and long-term dependencies.
- **Spatio-Temporal Group Learning:** Groups kingdoms with similar climates for better generalization.
- **Feature Engineering Pipeline:** Implements physics-informed transformations and smoothing techniques.
- **Adaptive Forecasting Framework:** Combines deep learning predictions with seasonal pattern adjustments.

## Repository Structure
```
📂 Harveston_Climate_Forecasting
│── 📂 data                # Dataset files (if applicable)
│── 📂 notebooks           # Jupyter Notebook files (.ipynb)
│── 📂 models              # Trained models and scripts
│── 📂 src                 # Source code for preprocessing and training
│── 📜 README.md           # Project documentation
│── 📜 requirements.txt    # Dependencies for setup
```

## How to Run
### Prerequisites
- Python 3.8+
- Install dependencies:
  ```bash
  pip install -r requirements.txt
  ```

### Running the Notebook
1. Open the Jupyter Notebook:
   ```bash
   jupyter notebook
   ```
2. Navigate to the `.ipynb` file and run the cells sequentially.

## Contributors
- **Team RainMakers - Data_Crunch_025**

## Acknowledgments
We acknowledge the competition organizers and University of Moratuwa for their support.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
