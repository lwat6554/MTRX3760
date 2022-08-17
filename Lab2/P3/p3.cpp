#include <iostream>
#include <string>

//-----------------------------------
struct PoseStruct
{
double Pos[3];
double Angle[3];
};
//-----------------------------------
class Platform
{
public:
virtual void EmergencyStop() = 0;
};
//-----------------------------------
class MobilePlatform: public Platform
{
public:
virtual void EmergencyStop() {}
virtual void MoveTowards( PoseStruct& Pose ) {}
PoseStruct& GetPose() { return mPose; }
private:
PoseStruct mPose;
};

//-----------------------------------
class TwoArmedTorso
{
public:
void ReachTowards( int ArmIdx, PoseStruct& Pose );
void GripperOpen();
};
//-----------------------------------
class WheeledRobot: public MobilePlatform
{
public:
void MoveTowards( PoseStruct& Pose ) {}
void SetSteeringAngle( double Angle );
void SetAcceleration( double Accel );
};

int main() {
    
}