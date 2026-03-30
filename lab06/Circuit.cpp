#include "Circuit.h"
#include <iostream>

Circuit::Circuit(): carCount(0),length(0.0),weather(Weather::Sunny){}

Circuit::~Circuit(){
    for(int i=0;i<carCount;i++)
       delete cars[i];
}

void Circuit::SetLength(double length){
    this->length=length;
}

void Circuit::SetWeather(Weather weather){
    this->weather=weather;
}

void Circuit::AddCar(Car* car){
    if(carCount<MAX_CARS)
        cars[carCount++]=car;
}

void Circuit::Race(){
    for(int i=0;i<carCount;i++){
        Car* c=cars[i];
        double maxdistance=(c->GetFuelCapacity()/c->GetFuelConsumption())*100.0;

        results[i].car=c;
        if(maxdistance>=length){
            results[i].finished=true;
            results[i].time=length/c->GetAverageSpeed(weather);
        }
        else{
            results[i].finished=false;
            results[i].time=0.0;
        }
    }

    for(int i=0;i<carCount-1;i++)
      for(int j=i+1;j<carCount;j++){
         bool ok=false;
         if(results[i].finished && results[j].finished)
            if(results[i].time>results[j].time)
               ok=true;
        else if(!results[i].finished && results[j].finished)
                ok=true;
        if(ok){
            Result aux=results[i];
            results[i]=results[j];
            results[j]=aux;
        }
      }
}

void Circuit::ShowFinalRanks(){
    int rank=1;
    for(int i=0;i<carCount;i++){
        if(results[i].finished){
            std::cout<<rank++<<". "<<results[i].car->GetName()<<"-time: "<<results[i].time;
        }
    std::cout<<"\n";
    }
}

void Circuit::ShowWhoDidNotFinish(){
    for(int i=0;i<carCount;i++){
        if(!results[i].finished)
           std::cout<<results[i].car->GetName()<<"\n";
    }
}