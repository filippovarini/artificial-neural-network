#include "ann.h"

/* Creates and returns a new ann. */
ann_t *ann_create(int num_layers, int *layer_outputs)
{
  ann_t *annPtr = malloc(sizeof(ann_t));
  if (annPtr == NULL) 
    return NULL;
  
  layer_t *prev = NULL;
  later_t *next = NULL;
  for (int i = 0; i < num_layers; i++) 
  {
    layer_t *curr = next;
    if (i == num_layers - 1) // Output layer
    { 
      annPtr->output_layer = curr;
    } else {
      // Set up next layer
      next = layer_create();
      if (next == NULL) 
        return NULL;
    }
    
    if (i == 0) // Input layer 
      annPtr->input_layer = curr;

   
    if(layer_init(curr, layer_outputs[i], prev)) // Mem Allocation failure 
      return NULL;
    
    // Set connections
    curr->prev = prev;
    curr->next = next;
    prev = layer;
  }
  return annPtr;
}

/* Frees the space allocated to ann. */
void ann_free(ann_t *ann)
{
  /**** PART 2 - QUESTION 2 ****/

  /* 2 MARKS */
}

/* Forward run of given ann with inputs. */
void ann_predict(ann_t const *ann, double const *inputs)
{
  /**** PART 2 - QUESTION 3 ****/

  /* 2 MARKS */
}

/* Trains the ann with single backprop update. */
void ann_train(ann_t const *ann, double const *inputs, double const *targets, double l_rate)
{
  /* Sanity checks. */
  assert(ann != NULL);
  assert(inputs != NULL);
  assert(targets != NULL);
  assert(l_rate > 0);

  /* Run forward pass. */
  ann_predict(ann, inputs);

  /**** PART 2 - QUESTION 4 ****/

  /* 3 MARKS */
}
