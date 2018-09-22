require __dir__ + "/spec_helper"
require __dir__ + '/../fp01_01.rb'

describe " 演習1" do
  it "width 5, height6" do
    results = triarea1(5,6)
    expect(results).to eq 15.0
  end
  it "width 5, height 6.0" do
    results = triarea1(5,6.0)
    expect(results).to eq 15.0
  end
  it "width 10.0, height 0" do
    results = triarea1(10.0,0)
    expect(results).to eq 0.0
  end
  it "width 5, height nil" do
    results = triarea1(5,nil)
    expect(results).to be_a(TypeError)
  end
end

describe "演習2" do
  it "height 3, width 3" do
    results = triarea2(3,3)
    expect(results).to match(4)
  end
  it "height 3, width 3.0" do
    results = triarea2(3,3.0)
    expect(results).to match(4.5)
  end
  it "height 0, width 0.0" do
    results = triarea2(0,0.0)
    expect(results).to match(0.0)
  end
  it "height nil, width 0.0" do
    results = triarea2(nil,0.0)
    expect(results).to be_a(NoMethodError)
  end
end

describe "演習3" do
  describe "a" do
    describe "Times" do
      it "2 times 3.0" do
        results = q_003_a_times(2,3.0)
        expect(results).to eq 6.0
      end
      it "5 times 10" do
        results = q_003_a_times(5,10)
        expect(results).to eq 50
      end
      it "5 times 10" do
        results = q_003_a_times(0,0)
        expect(results).to eq 0
      end
      it "5 times nil" do
        results = q_003_a_times(5,nil)
        expect(results).to be_a(TypeError)
      end
      it "nil times 3" do
        results = q_003_a_times(nil,3)
        expect(results).to be_a(NoMethodError)
      end
    end
    describe "Div" do
      it "1 / 3" do
        results = q_003_a_div(1,3)
        expect(results).to eq 0
      end
      it "20 / 3" do
        results = q_003_a_div(20,3)
        expect(results).to eq 6
      end
      it "1.0 / 3" do
        results = q_003_a_div(1.0,3)
        expect(results.to_s).to match(/^[0]{1}\.[3]+$/)
      end
      it "5 / nil " do
        results = q_003_a_div(5,nil)
        expect(results).to be_a(TypeError)
      end
      it "nil / 5 " do
        results = q_003_a_div(nil,5)
        expect(results).to be_a(NoMethodError)
      end
    end
    describe "Plus" do
      it "7 + 10" do
        results = q_003_a_plus(7,10)
        expect(results).to eq 17
      end
      it "-8 + 9.0" do
        results = q_003_a_plus(-8,9.0)
        expect(results).to eq 1.0
      end
      it "6 + nil " do
        results = q_003_a_plus(6,nil)
        expect(results).to be_a(TypeError)
      end
      it "nil + 5 " do
        results = q_003_a_plus(nil,5)
        expect(results).to be_a(NoMethodError)
      end
    end
    describe "" do
      it "8 - 10" do
        results = q_003_a_diff(8,10)
        expect(results).to eq -2
      end
      it "1 - 2.0" do
        results = q_003_a_diff(1,-2.0)
        expect(results).to eq 3.0
      end
      it "0 - nil " do
        results = q_003_a_diff(0,nil)
        expect(results).to be_a(TypeError)
      end
      it "nil - 22.1 " do
        results = q_003_a_diff(nil,22.1)
        expect(results).to be_a(NoMethodError)
      end
    end
  end
  describe "b" do
    it "5 % 1" do
      results = q_003_b(5,1)
      expect(results).to eq 0
    end
    it "9 % 2" do
      results = q_003_b(9,2)
      expect(results).to eq 1
    end
    it "7 % 3.0" do
      results = q_003_b(7,3.0)
      expect(results).to eq 1.0
    end
    it "2 % 0" do
      results = q_003_b(2,0)
      expect(results).to be_a(ZeroDivisionError)
    end
    it "0 % 2" do
      results = q_003_b(0,2.0)
      expect(results).to eq 0.0
    end
    it "4 % nil" do
      results = q_003_b(4,nil)
      expect(results).to be_a(TypeError)
    end
    it "nil % 5" do
      results = q_003_b(nil,5)
      expect(results).to be_a(NoMethodError)
    end
  end
  describe "c" do
    it "10" do
      results = q_003_c(10)
      expect(results).to match(/^[0]{1}\.[1]{1}[0]+/)
    end
    it "0.0002" do
      results = q_003_c(0.0002)
      expect(results).to match(/^[5]{1}[0]{3}\.[0]+/)
    end
    it "0.0002" do
      results = q_003_c(nil)
      expect(results).to be_a(NoMethodError)
    end
  end
  describe "d" do
    it "2, 2" do
      results = q_003_d(2,2)
      expect(results.to_s).to match(/^[4]{1}\.[0]+$/)
    end
    it "2, -2" do
      results = q_003_d(2,-2)
      expect(results.to_s).to match(/^0.25e0$/)
    end
    it "2, nil" do
      results = q_003_d(2,nil)
      expect(results).to be_a(NoMethodError)
    end
    it "nil, 10" do
      results = q_003_d(nil,10)
      expect(results).to match(/^[0]{1}\.[0]+$/)
    end
  end
end
