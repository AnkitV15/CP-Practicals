// Ankit Vishwakarma 
#include <iostream>
#include <vector>
#include <limits> // For numeric_limits

using namespace std;

// Function to calculate distance between two cities
double distance(const vector<vector<double>>& distances, int i, int j) {
  return distances[i][j];
}

// Function to find the nearest unvisited city from a given city
int nearestUnvisitedCity(const vector<vector<double>>& distances, const vector<bool>& visited, int currentCity) {
  int minIndex = -1;
  double minDistance = numeric_limits<double>::infinity(); // Initialize with infinity

  for (int i = 0; i < distances.size(); i++) {
    if (!visited[i] && distance(distances, currentCity, i) < minDistance) {
      minIndex = i;
      minDistance = distance(distances, currentCity, i);
    }
  }

  return minIndex;
}

// Function to find the total distance of the travel route
double calculateTotalDistance(const vector<vector<double>>& distances, const vector<int>& tour) {
  double totalDistance = 0;
  for (int i = 0; i < tour.size() - 1; i++) {
    totalDistance += distance(distances, tour[i], tour[i + 1]);
  }
  // Add distance from last city back to the starting city
  totalDistance += distance(distances, tour[tour.size() - 1], tour[0]);
  return totalDistance;
}

// Function to implement the Nearest Neighbor Heuristic for TSP
vector<int> nearestNeighborTSP(const vector<vector<double>>& distances) {
  int n = distances.size(); // Number of cities

  vector<bool> visited(n, false); // Keep track of visited cities
  visited[0] = true; // Start from the first city

  vector<int> tour(n); // Stores the tour (visited cities in order)
  tour[0] = 0; // Starting city

  // Build the tour by finding the nearest unvisited city from the current city
  for (int i = 1; i < n; i++) {
    int nextCity = nearestUnvisitedCity(distances, visited, tour[i - 1]);
    visited[nextCity] = true;
    tour[i] = nextCity;
  }

  return tour;
}

int main() {
  // Sample distance matrix (replace with your actual data)
  vector<vector<double>> distances = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
  };

  vector<int> tour = nearestNeighborTSP(distances);
  cout << "Tour using Nearest Neighbor Heuristic: ";
  for (int city : tour) {
    cout << city << " -> ";
  }
  cout << tour[0] << endl; // Print the starting city again to complete the cycle

  double totalDistance = calculateTotalDistance(distances, tour);
  cout << "Total Distance: " << totalDistance << endl;

  return 0;
}
