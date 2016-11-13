

class Component {
  virtual void update(float ms);
  virtual void draw();
  std::string getComponentTypeID();

  virtual ~Component();
};
