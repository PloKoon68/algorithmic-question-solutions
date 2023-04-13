package com.testt;

import java.util.ArrayList;
import java.util.List;


public class Main {
    public static double realFunc(double x) {
        return x * Math.exp(0.5D * x) + 1.2D * x - 5.0D;
    }

    public static double derrivative(double x) {
        return Math.sin(x);
    }
  
}
