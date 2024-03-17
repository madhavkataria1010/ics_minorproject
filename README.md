
---

# Logistic Regression in C

This project provides a basic implementation of logistic regression in C. Logistic regression is a linear model commonly used for binary classification tasks.

## Overview

- `Logistic_Regression.c`: The main C source file containing the implementation of logistic regression.
- `data.csv`: Sample dataset in CSV format for training the logistic regression model.

## Usage

1. **Compile the code:**
   ```sh
   gcc Logistic_Regression.c -o Logistic_Regression -lm
   ```

2. **Run the executable:**
   ```sh
   ./Logistic_Regression
   ```

## Data Format

The input data should be in CSV format with the last column containing the class labels. Each row represents a data point, where the first `n_in` columns are the features and the last column is the class label. For example:
```
x1,x2,x3,x4,x5,x6,y
1,2,3,4,5,6,0
7,8,9,10,11,12,1
...
```

## Parameters

- `learning_rate`: The learning rate determines the step size taken during optimization.
- `n_epochs`: The number of epochs defines how many times the algorithm will iterate over the entire dataset during training.
- `n_in`: The number of input features in the dataset.
- `n_out`: The number of output classes (2 for binary classification).

## Output

The code outputs the accuracy of the model on the training dataset for each epoch. The accuracy is calculated as the percentage of correctly predicted labels.

## Implementation Details

- The `LR` struct represents the logistic regression model, containing the weights `W` and biases `b`.
- The `LR_construct` function initializes the model with random weights and biases.
- The `LR_train` function performs gradient descent to update the weights and biases based on the training data.
- The `LR_predict` function predicts the class label for a given input using the trained model.
- The `LR_softmax` function applies the softmax activation function to convert model outputs into class probabilities.

## License

This project is licensed under the MIT License - see the `LICENSE` file for details.

---
## Made by 
- Madhav Kataria 
- Roll no - B23CH1025 


