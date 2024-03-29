#include "Geometries.hpp"
#include "PixelBuffer.hpp"

using namespace std;

///////////PixelBuffer///////////

PixelBuffer::PixelBuffer(char bg, int w, int h) : m_bgChar(bg), m_width(w), m_height(h), m_pixelBuffer(m_height,vector<char>(m_width, bg)) {}

void PixelBuffer::setDimension(const int w, const int h)
{
    m_width = w;
    m_height = h-1;
}


void PixelBuffer::draw() const
{
    for(int y = 0; y < m_height; ++y)
    {
        for(int x = 0; x < m_width; ++x)
        {
            cout << m_pixelBuffer[y][x];
        }
    }
    cout << endl;
}

bool PixelBuffer::isInBuffer(Point2D p)
{
    int x = p.getCoord()[0];
    int y = p.getCoord()[1];
    return (x > 0 && x<m_width && y >= 0 && y < m_height);
}

void PixelBuffer::putPixel(char pixel, Point2D p)
{
    int x = round(p.getCoord()[0]);
    int y = round(p.getCoord()[1]);
    
    if (isInBuffer(p))
    {
        m_pixelBuffer[y][x] = pixel;
    }
}

void PixelBuffer::putTriangle2D(Triangle2D tri)
{
    vector<double> limits = tri.limitTriangle2D();
    int xMin, xMax, yMin, yMax;
    xMin = round(limits[0]);
    xMax = round(limits[1]);
    yMin = round(limits[2]);
    yMax = round(limits[3]);

    for(int y = yMin; y < yMax; ++y)
    {
        for(int x = xMin; x < xMax; ++x)
        {
            Point2D p(x,y);
            if (p.isInTriangle2D(tri))
            {
                putPixel(tri.getPixel(), p);
            }
        }
    }
}

void PixelBuffer::putMesh(vector<Triangle3D> mesh, Camera cam)
{
    for (int i=0; i<mesh.size(); i++)
    {
        putTriangle2D(mesh[i].translate(cam.getPos()).rotationY(cam.getYaw()).rotationX(cam.getPitch()).projection(cam.getFocalLength()));
    }
}

void PixelBuffer::displayCamParam(Camera cam)
{
    string param = "Pos: (" + to_string(cam.getPos().getCoord()[0]) + ", " + to_string(cam.getPos().getCoord()[1]) + ", " + to_string(cam.getPos().getCoord()[2]) + ")" + " | Pitch: " + to_string(cam.getPitch()) + " | Yaw : " + to_string(cam.getYaw());
    if (param.length() < m_width)
    {
        for (int i=0; i<param.length(); i++)
        {
            m_pixelBuffer[m_height-1][i+1] = param[i];
        }
    }
}
    

void PixelBuffer::clear()
{
    m_pixelBuffer = vector<vector<char>>(m_height, vector<char>(m_width, m_bgChar));
}

///////////Camera///////////

Camera::Camera(Point3D position, double pitch, double yaw) : m_position(position), m_originPosition(position), m_pitch(pitch), m_yaw(yaw), m_focalLength(1) {}

Point3D Camera::getPos()
{
    double x = m_position.getCoord()[0]*(-1);
    double y = m_position.getCoord()[1]*(-1);
    double z = m_position.getCoord()[2]*(-1);
    return(Point3D(x,y,z));
}

Point3D Camera::getOriginPos()
{
    return(m_originPosition);
}

double Camera::getPitch()
{
    return(m_pitch);
}

double Camera::getYaw()
{
    return(m_yaw);
}

double Camera::getFocalLength()
{
    return(m_focalLength);
}

void Camera::setPos(const Point3D P)
{
    m_position = m_position + P;
}

void Camera::setPitch(const double c)
{
    m_pitch += c;
}

void Camera::setYaw(const double c)
{
    m_yaw += c;
}

void Camera::setFocalLength(const double c)
{
    m_focalLength += c;
}



// Point3D Camera::getLookDirection()
// {
//     return(1);
// }

Point3D Camera::getForwardDirection()
{
    return(Point3D(-sin(m_yaw),0,cos(m_yaw)));
}

Point3D Camera::getRightDirection()
{
    return(Point3D(cos(m_yaw),0,sin(m_yaw)));
}