#include <iostream>
#include <memory>
#include <string>

class CalibrationData {
public:
    CalibrationData(std::string n) : camera_id(n) {
        std::cout << "✓ Calibration data loaded for camera '" << camera_id << "'" << std::endl;
    }
    ~CalibrationData() {
        std::cout << "✗ Calibration data released for camera '" << camera_id << "'" << std::endl;
    }
    void getMatrix() {
        std::cout << "calibration matrix for '" << camera_id << "'" << std::endl;
    }
private:
    std::string camera_id;
};

class PointCloudProcessor {
public:
    void setCalibration(std::shared_ptr<CalibrationData> calib) {
        calibration = calib;
    }
    void process() {
        if (calibration) {
            std::cout << "[PointCloud] Processing with ";
            calibration->getMatrix();
        }
    }
private:
    std::shared_ptr<CalibrationData> calibration;
};

class ImageCorrector {
public:
    void setCalibration(std::shared_ptr<CalibrationData> calib) {
        calibration = calib;
    }
    void correct() {
        if (calibration) {
            std::cout << "[ImageCorrector] Correcting with ";
            calibration->getMatrix();
        }
    }
private:
    std::shared_ptr<CalibrationData> calibration;
};

int main() {
    std::cout << "=== SCANNER 3D CALIBRATION ===" << std::endl;
    
    auto calibration = std::make_shared<CalibrationData>("Camera-001");
    std::cout << "Reference count: " << calibration.use_count() << "\n" << std::endl;
    
    PointCloudProcessor pointCloud;
    ImageCorrector corrector;
    
    pointCloud.setCalibration(calibration);
    std::cout << "After PointCloud: " << calibration.use_count() << "\n" << std::endl;
    
    corrector.setCalibration(calibration);
    std::cout << "After Corrector: " << calibration.use_count() << "\n" << std::endl;
    
    pointCloud.process();
    corrector.correct();
    
    std::cout << "\n=== Exiting ===" << std::endl;
    
    return 0;
}