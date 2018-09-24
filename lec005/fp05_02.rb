require __dir__ + '/../modules/fp_image.rb'

def a
  begin
    obj = FpImage.new
    obj.fillcircle(100,100,90,39,38,144)
    obj.fillcircle(100,100,80,0,0,255)
    obj.fillcircle(100,100,50,25,135,22)
    obj.writeimage("img/2a.ppm")
    return true
  rescue => e
    return e
  end
end

def b
  begin
    obj = FpImage.new
    obj.fillcircle(50,50,50,0,0,255)
    obj.fillcircle(150,50,50,0,0,255)
    obj.fillcircle(50,150,50,0,0,255)
    obj.fillcircle(150,150,50,0,0,255)
    obj.writeimage("img/2b.ppm")
    return true
  rescue => e
    return e
  end
end

def c
  begin
    obj = FpImage.new
    obj.fillcircle(20,20,20,0,0,255)
    obj.fillcircle(60,60,20,0,0,255)
    obj.fillcircle(100,100,20,0,0,255)
    obj.fillcircle(140,140,20,0,0,255)
    obj.writeimage("img/2c.ppm")
    return true
  rescue => e
    return e
  end
end

def d
  begin
    obj = FpImage.new
    obj.fillcircle(50,100,50,0,0,255)
    obj.fillcircle(140,100,40,0,0,255)
    obj.fillcircle(210,100,30,0,0,255)
    obj.fillcircle(260,100,20,0,0,255)
    obj.fillcircle(290,100,10,0,0,255)
    obj.writeimage("img/2d.ppm")
    return true
  rescue => e
    return e
  end
end
