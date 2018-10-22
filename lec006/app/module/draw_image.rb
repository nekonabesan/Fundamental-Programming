require __dir__ + '/../../../modules/fp_image.rb'
=begin
図形クラスを呼び出し風景オブジェクトを生成するクラス
=end
class DrowImage
  def initialize
    @obj = FpImage.new
    # 葉の色相を配列として初期化
    @c_reef = {
      0 => [47,79,54],
      1 => [51,96,69],
      2 => [224,234,58],
      3 => [209,232,41],
      4 => [127,246,85],
      5 => [0,255,65],
      6 => [11,218,81],
      7 => [107,191,63],
      8 => [88,191,63],
      9 => [34,195,80]
    }
  end

  def draw(sw, x0, y0, c = 0)
    begin
      raise ArgumentError if sw.nil? || x0.nil? || y0.nil?
      if sw == 'tree1' then
        puts('tree1')
        self.drowTree01(x0, y0, c)
      elsif sw == 'tree2' then
        puts('tree2')
        self.drowTree02(x0, y0, c)
      else
        return false
      end
      return true
    rescue => e
      return e
    end
  end

=begin
ディレクトリへ画像ファイルを出力するメソッド
param String file name
return bool
=end
  def write(fname = 'test')
    begin
      @obj.writeimage("img/" + fname + ".ppm")
      @onj = nil
      return true
    rescue => e
      return e
    end
  end

=begin
背景画像生成メソッド
=end
  def drawBackGroundImage
    begin
      #/=============================================/
      #  背景
      #/=============================================/
      @obj.rectangle(150,100,300,200,67,135,233)
      @obj.rectangle(150,160,300,80,171,255,127)
      #/=============================================/
      #  背景の山
      #/=============================================/
      # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
      @obj.triangle(150,30,-80,120,200,120,255,255,255)
      # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
      @obj.triangle(200,30,0,120,300,120,86,99,143)
      # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
      @obj.triangle(40,20,-40,120,80,120,231,232,226)
      # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
      @obj.triangle(260,20,180,120,360,120,231,232,226)
      # ellipse(x0, y0, prm_a, prm_b, r, g, b)
      #/=============================================/
      # 湖
      #/=============================================/
      @obj.ellipse(100,160,60,20,0,0,255)
      @obj.ellipse(0,180,120,40,0,0,255)
    rescue => e
      return e
    end
  end

=begin
 三角形と長方形を組み合わせて「木」を生成するメソッド
 param int x座標
 param int y座標
 param int 葉の色
 return bool
=end
  def drowTree01(x0, y0, c = 0)
    begin
      raise ArgumentError if x0.nil? || y0.nil?
      # rectangle(x, y, w, h, r, g, b)
      @obj.rectangle(x0, y0 + 80, 4, 40, 93, 93, 33)
      # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
      @obj.triangle(x0, y0, x0 - 10, y0 + 40, x0 + 10, y0 + 40, @c_reef[c][0],@c_reef[c][1],@c_reef[c][2])
      # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
      @obj.triangle(x0, y0 + 20, x0 - 15,y0 + 60, x0 + 15,y0 + 60, @c_reef[c][0],@c_reef[c][1],@c_reef[c][2])
      # triangle(x0, y0, x1, y1, x2, y2, r, g, b)
      @obj.triangle(x0, y0 + 50 ,x0 - 20 , y0 + 80, x0 + 20, y0 + 80, @c_reef[c][0],@c_reef[c][1],@c_reef[c][2])
      return true
    rescue => e
      return e
    end
  end

=begin
 楕円と長方形を組み合わせて「木」を生成するメソッド
 param int x座標
 param int y座標
 param int 葉の色
 return bool
=end
  def drowTree02(x0, y0, c = 0)
    begin
      raise ArgumentError if x0.nil? || y0.nil?
      # Tree Obj01
      # rectangle(x, y, w, h, r, g, b)
      @obj.rectangle(x0, y0 + 60, 4, 40, 93, 93, 33)
      # ellipse(x0, y0, prm_a, prm_b, r, g, b)
      @obj.ellipse(x0, y0, 20, 50, @c_reef[c][0], @c_reef[c][1], @c_reef[c][2])
    rescue => e
      return e
    end
  end
end
