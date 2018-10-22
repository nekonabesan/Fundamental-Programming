require __dir__ + '/app/module/draw_image.rb'
=begin
オブジェクトの生成をクラスへ切り分けた実装例
※処理は簡素だが定型的なオブジェクトしか生成できない。
=end
def a
  obj = DrowImage.new
  obj.drawBackGroundImage
  obj.draw('tree1',10,30,0)
  obj.draw('tree1',30,30,1)
  obj.draw('tree1',50,30,1)
  obj.draw('tree1',70,30,1)
  obj.draw('tree1',90,30,0)
  obj.draw('tree1',110,30,1)
  obj.draw('tree1',130,30,0)
  obj.draw('tree1',150,30,1)
  obj.draw('tree1',170,30,0)
  obj.draw('tree1',190,30,1)
  obj.draw('tree1',170,30,0)
  obj.draw('tree1',190,30,1)
  obj.draw('tree1',210,30,0)
  obj.draw('tree1',230,30,1)
  obj.draw('tree1',250,30,0)
  obj.draw('tree1',270,30,1)
  obj.draw('tree1',290,30,0)
  obj.draw('tree1',310,30,1)
  obj.draw('tree1',20,40,9)
  obj.draw('tree1',40,40,8)
  obj.draw('tree1',60,40,7)
  obj.draw('tree1',80,40,1)
  obj.draw('tree1',100,40,9)
  obj.draw('tree1',120,40,8)
  obj.draw('tree1',140,40,7)
  obj.draw('tree1',160,40,1)
  obj.draw('tree1',180,40,9)
  obj.draw('tree1',200,40,8)
  obj.draw('tree2',240,70,1)
  obj.draw('tree2',250,80,2)
  obj.draw('tree2',260,70,3)
  obj.draw('tree2',270,80,4)
  obj.draw('tree2',280,70,5)
  obj.write
  return true
end
