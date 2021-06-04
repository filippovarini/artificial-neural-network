#include "layer.h"

/** Initialize array to 0 */
void initialize_arr_to_zero(double *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    arr[i] = 0;
  }
}

/** Initialize 2D array to random values. */
void initialize_weights(double **weights, int rows, int cols)
{
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
      weights[r][c] = ANN_RANDOM();
    }
  }
}

/* The sigmoid function and derivative. */
double sigmoid(double x)
{
  double y = exp(x);
  return y / (y + 1);
}

double sigmoidprime(double x)
{
  return x * (1 - x);
}

/* Creates a single layer. */
layer_t *layer_create()
{
  layer_t *layer_addr = malloc(sizeof(layer_t));
  if (layer_addr == NULL)
  {
    return NULL;
  }

  // initializing the layer
  layer_addr->num_inputs = 0;
  layer_addr->num_outputs = 0;
  layer_addr->prev = NULL;
  layer_addr->next = NULL;
  layer_addr->weights = NULL;
  layer_addr->biases = NULL;
  layer_addr->deltas = NULL;

  return layer_addr;
}

/* Initialises the given layer. */
bool layer_init(layer_t *layer, int num_outputs, layer_t *prev)
{
  // Allocate outputs
  double *outputs = calloc(num_outputs, sizeof(double));
  if (outputs == NULL)
    return true;
  layer->num_outputs = num_outputs;
  layer->outputs = outputs;

  if (prev != NULL)
  {
    // Not input layer
    layer->num_inputs = prev->num_outputs;
    layer->prev = prev;

    // Allocate biases and deltas
    double *deltas = calloc(num_outputs, sizeof(double));
    double *biases = calloc(num_outputs, sizeof(double));
    layer->biases = biases;
    layer->deltas = deltas;
    if (deltas == NULL || biases == NULL)
      return true;

    // Allocate weights
    double **weights = calloc(num_outputs, sizeof(double *));
    if (weights == NULL)
      return true;
    for (int r = 0; r < num_outputs; r++)
    {
      weights[r] = calloc(layer->num_inputs, sizeof(double));
      if (weights[r] == NULL)
        return true;
    }

    // Initialize
    initialize_arr_to_zero(outputs, num_outputs);
    initialize_arr_to_zero(deltas, num_outputs);
    initialize_arr_to_zero(biases, num_outputs);
    initialize_weights(weights, num_outputs, layer->num_inputs);
  }

  return false;
}

/* Frees a given layer. */
void layer_free(layer_t *layer)
{
  /**** PART 1 - QUESTION 4 ****/

  /* 2 MARKS */
}

/* Computes the outputs of the current layer. */
void layer_compute_outputs(layer_t const *layer)
{
  /**** PART 1 - QUESTION 5 ****/
  /* objective: compute layer->outputs */

  /* 3 MARKS */
}

/* Computes the delta errors for this layer. */
void layer_compute_deltas(layer_t const *layer)
{
  /**** PART 1 - QUESTION 6 ****/
  /* objective: compute layer->deltas */

  /* 2 MARKS */
}

/* Updates weights and biases according to the delta errors given learning rate. */
void layer_update(layer_t const *layer, double l_rate)
{
  /**** PART 1 - QUESTION 7 ****/
  /* objective: update layer->weights and layer->biases */

  /* 1 MARK */
}
