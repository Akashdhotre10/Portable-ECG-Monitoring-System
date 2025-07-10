import processing.serial.*;  // Import serial library for communication
 
Serial myPort;              // Serial port object
int xPos = 1;               // X position for plotting the graph
float height_old = 0;
float height_new = 0;
float inByte = 0;
int BPM = 0;
int beat_old = 0;
float[] beats = new float[500];  // Array to store recent BPM values
int beatIndex;
float threshold = 620.0;         // Threshold value to detect a heartbeat
boolean belowThreshold = true;
PFont font;

void setup () {
  size(1000, 400);          // Set canvas size

  println(Serial.list());   // Print all available serial ports
  myPort = new Serial(this, Serial.list()[2], 9600); // Open the appropriate port
  myPort.bufferUntil('\n'); // Read serial data until newline character
  
  background(255);          // Set background to white
  font = createFont("Arial", 12, true);
}

void draw () {
  // Map and plot incoming signal data
  inByte = map(inByte, 0, 1023, 0, height);
  height_new = height - inByte; 
  line(xPos - 1, height_old, xPos, height_new);
  height_old = height_new;
  
  // Reset the screen if graph reaches the end
  if (xPos >= width) {
    xPos = 0;
    background(255);
  } else {
    xPos++;
  }
  
  // Display BPM text periodically
  if (millis() % 128 == 0){
    fill(255);
    rect(0, 0, 200, 20);
    fill(0);
    text("BPM: " + BPM, 15, 10);
  }
}

void serialEvent (Serial myPort) {
  // Read serial data as a string
  String inString = myPort.readStringUntil('\n');
  
  if (inString != null) {
    inString = trim(inString);
    
    // Lead-off detection — draw blue flatline
    if (inString.equals("!")) { 
      stroke(0, 0, 255);
      inByte = 512;
    } 
    // Valid data received
    else {
      stroke(255, 0, 0);
      inByte = float(inString); 
      
      // Check for heartbeat
      if (inByte > threshold && belowThreshold) {
        calculateBPM();
        belowThreshold = false;
      } else if (inByte < threshold) {
        belowThreshold = true;
      }
    }
  }
}

void calculateBPM () {
  int beat_new = millis();              // Get current time
  int diff = beat_new - beat_old;      // Time between two beats
  float currentBPM = 60000.0 / diff;   // Calculate BPM from time interval
  
  beats[beatIndex] = currentBPM;       // Store in circular buffer
  float total = 0.0;
  
  for (int i = 0; i < 500; i++) {
    total += beats[i];
  }
  
  BPM = int(total / 500);              // Average BPM value
  beat_old = beat_new;
  beatIndex = (beatIndex + 1) % 500;   // Move to next index
}
