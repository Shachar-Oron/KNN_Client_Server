# ap_ex2
## Description
project of the second exercise in ap course, implementation of the KNN learning machine algorithm.

 ## About the project
in this exercise the code gets 3 arguments from the user-
'k' - in the knn algorythem, is a number of neighbors we would like to calculate the distences from. it shuld be a positive int value.
'file'- is the path to a file that contains the data set with the classificated or unclassificated data.
'distance'- could be: AUC, MAN, CHB, CAN, MIN. means the way the distance will be calulated.
In the previous exercise, we have created a class named DistancesCalcolators that has different functions that calculates the different distances.
  the types of distances are: 
  - Euclidean distance (AUC)
  - Manhattan distance (MAN)
  - Chebyshev distance (CHB)
  - Canberra distance (CAN)
  - Minkowski distance with const p = 2 (MIN)
  
   ## About the algorithm:
   There are different ways to implement the KNN algorithm. in our code we make the next steps:
   - find the K nearest neighbors of the input by the Distances Calcolators functions.
   - find the common label of the input's neighbors.
   - now we know the common label, we will classify the input by this common lable.
    At first, the user will load a classified data set as an input and the algorithm will Calcolates the results of the K nearest neighbors.
    Then, the user will input a vector of features (in a forrm of numbers with spaces) and the output eould be the label of the input's vector.
    The lable is provide according to the k, file and distance the user has inserted.

 
 ## Getting Started
### Running  the app :
After you have download the attached files

 * open the terminal
 * run   ```make ```
 * run  ```./a.out k file distance```
 * insert a vector in the forrm of numbers with spaces 

### New optimisations in the code:
- A load data class that reads the inputs value with the inserted path
- A Knn class that uses the Distances Calcolators class to find the common label of the input's nearest neighbors.

### A disclaimer:
We had difficulties with using the git push, pull and merge. We accidentally did a merge in a wrong way that some cmake file were overwritten in the project. The result was that one student could run the project in his computer and the other could'nt. We tried to fix this problem, meanwhile the grandfather of Liel's husbend past away and it was difficult to work together.
We have decided to start all over, open a new repository and copy & paste all the code we've written. That's why all of the project has done in Liel's branch, not like the instructions and we are aware of that.
We hope you can consider our case and consider the fact that our project started in the proper way on git and crushed later on.  We didn't have enough time to fix this properly. 
Therefor, if you can, we ask you to look for our workflow and issues at: https://github.com/Shachar-Oron/ap_ex2.
