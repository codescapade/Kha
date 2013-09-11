package kha.wpf;

import kha.Animation;
import kha.FontStyle;
import kha.Image;
import kha.Rotation;
import system.windows.media.Color;
import system.windows.media.DrawingContext;

class Painter extends kha.Painter {
	public var context: DrawingContext;
	private var color: Color;
	private var font: Font;
	private var tx: Float;
	private var ty: Float;

	public function new() {
		font = new Font("Arial", new FontStyle(false, false, false), 20);
	}
	
	override public function translate(x: Float, y: Float): Void {
		tx = x;
		ty = y;
	}
	
	@:functionCode('
		var img = (Image)image;
		context.DrawImage(img.image, new System.Windows.Rect(tx + x, ty + y, img.get_width(), img.get_height()));
	')
	override public function drawImage(image: Image, x: Float, y: Float): Void {
		
	}

	@:functionCode('
		var img = (Image)image;
		//var cropped = new System.Windows.Media.Imaging.CroppedBitmap(img.image, new System.Windows.Int32Rect((int)sx, (int)sy, (int)sw, (int)sh));
		//context.DrawImage(cropped, new System.Windows.Rect(tx + dx, ty + dy, dw, dh)); //super slow
		var brush = new System.Windows.Media.ImageBrush(img.image);
		brush.Viewbox = new System.Windows.Rect(sx / img.get_width(), sy / img.get_height(), sw / img.get_width(), sh / img.get_height());
		context.DrawRectangle(brush, null, new System.Windows.Rect(tx + dx, ty + dy, dw, dh));
	')
	override public function drawImage2(image: kha.Image, sx: Float, sy: Float, sw: Float, sh: Float, dx: Float, dy: Float, dw: Float, dh: Float, rotation: Rotation = null): Void {
		
	}

	@:functionCode('
		if (text != null) {
			text.Replace(\' \', (char)160); // Non-breaking space 
			System.Windows.Media.FormattedText fText = new System.Windows.Media.FormattedText(text, 
				System.Globalization.CultureInfo.GetCultureInfo("en-us"), System.Windows.FlowDirection.LeftToRight,
				new System.Windows.Media.Typeface(font.get_name()), font.get_size(), new System.Windows.Media.SolidColorBrush(color));
			if (font.get_style().getBold()) fText.SetFontWeight(System.Windows.FontWeights.Bold);
			if (font.get_style().getItalic()) fText.SetFontStyle(System.Windows.FontStyles.Italic);
			if (font.get_style().getUnderlined()) fText.SetTextDecorations(System.Windows.TextDecorations.Underline);
			context.DrawText(fText, new System.Windows.Point(tx + x, ty + y));
		}
	')
	override public function drawString(text : String, x : Float, y : Float) : Void {
		
	}

	override public function setFont(font : kha.Font) : Void {
		this.font = cast(font, Font);
	}

	override public function setColor(color: kha.Color) : Void {
		setColorInternal(color.Ab, color.Rb, color.Gb, color.Bb);
	}
	
	@:functionCode('
		color = System.Windows.Media.Color.FromArgb((byte)a, (byte)r, (byte)g, (byte)b);
	')
	private function setColorInternal(a : Int, r : Int, g : Int, b : Int) : Void {
		
	}

	@:functionCode('
		context.DrawRectangle(null, new System.Windows.Media.Pen(new System.Windows.Media.SolidColorBrush(color), 1), new System.Windows.Rect(tx + x, ty + y, width, height));
	')
	override public function drawRect(x: Float, y: Float, width: Float, height: Float, strength: Float = 1.0): Void {
		
	}

	@:functionCode('
		context.DrawRectangle(new System.Windows.Media.SolidColorBrush(color), new System.Windows.Media.Pen(), new System.Windows.Rect(tx + x, ty + y, width, height));
	')
	override public function fillRect(x : Float, y : Float, width : Float, height : Float) : Void {
		
	}
	
	@:functionCode('
		context.DrawLine(new System.Windows.Media.Pen(new System.Windows.Media.SolidColorBrush(color), 1), new System.Windows.Point(tx + x1, ty + y1), new System.Windows.Point(tx + x2, ty + y2));
	')
	override function drawLine(x1: Float, y1: Float, x2: Float, y2: Float, strength: Float = 1.0): Void {
		
	}
		
	@:functionCode('
		context.DrawVideo(((Video)video).getPlayer(), new System.Windows.Rect(tx + x, ty + y, width, height));
	')
	override function drawVideo(video : kha.Video, x : Float, y : Float, width : Float, height : Float) : Void {

	}
}