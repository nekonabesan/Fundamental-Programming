require __dir__ + '/app/module/draw_image.rb'

def a
  obj = DrowImage.new
  obj.drawBackGroundImage
  obj.draw('tree1',40,30)
  obj.draw('tree1',60,40)
  obj.draw('tree1',80,30)
  obj.draw('tree2',120,70)
  obj.write
  return true
end
