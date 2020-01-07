package downloadimage;

import java.awt.Dimension;
import java.awt.image.BufferedImage;
import java.io.File; 
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL; 
import javax.imageio.ImageIO; 
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import mvc.Controller;
import mvc.Model;
import mvc.View;

/**
 * ウェブ上にある画像をダウンロードして、ローカルディスク(カレントディレクトリ)に保存し、その画像をウィンドウに表示する。
 * オブザーバ・デザインパターン(MVC: Model-View-Controller)を用いた典型的(模範的)なプログラム。
 */
public class Example extends Object
{
	/**
	 * URL文字列を設定して、URLのインスタンスを生成し、そのURLで指定された画像を読み込む。
	 * URLで指定された画像を読み込めなかった時にはエラー処理を行う。
	 * そして、読み込んだ画像をローカルディスク(カレントディレクトリ)に書き込む。
	 * その後、MVCを作って、それをウィンドウに乗せて出す。
	 * 3秒待ってから、MVCのモデルに表示物(当該の画像)を設定する。
     * 良好（2013年5月19日）
	 */
	public static void main(String[] arguments)
	{
		// URL文字列を設定する。
		String aString = "http://aokilab.kyoto-su.ac.jp/documents/SmalltalkIdioms/images/SmalltalkIdiomsFrontPage.jpg";

		// URLのインスタンスを生成する。
		URL aURL = null;
        try
        {
            aURL = new URL(aString);
        }
        catch(MalformedURLException anException)
        {
            System.err.println(anException);
        }
        

		// URLで指定された画像を読み込む。
        BufferedImage aBufferedImageFromURL = null;
        try
        {
            aBufferedImageFromURL = ImageIO.read(aURL);
            ;
        }
        // URLで指定された画像を読み込めなかった時のエラー処理を行う。
        catch(IOException anException)
        {
            System.err.println(anException);
            Example.boo(aString);
        }

        
		// 読み込んだ画像をローカルディスク(カレントディレクトリ)に書き込む。その後、localに置かれた画像から読み込む
        BufferedImage anBufferedImageFromLocal = null;
		try
        {
            ImageIO.write(aBufferedImageFromURL, "jpg", new File("wroteImage.jpg")); 
            anBufferedImageFromLocal = ImageIO.read(new File("wroteImage.jpg"));
        }
        catch(IOException anException)
        {
            System.err.println(anException);
        }

        
		// MVCを作る。
		Model aModel = new Model();
		View aView = new View(aModel);

		// MVCのビューをウィンドウに乗せて出す。
		Example.open(aView, new Dimension(anBufferedImageFromLocal.getWidth(), anBufferedImageFromLocal.getHeight()) );
        ;
        
		// 3秒待ってから、MVCのモデルに表示物(当該の画像)を設定する。
        try
        {
            Thread.sleep(3000);
        }
        catch (InterruptedException anException)
        {
            System.err.println(anException);
            throw new RuntimeException(anException.toString());
        }
        aModel.picture(anBufferedImageFromLocal);
		aModel.changed();
		return;
	}

	/**
	 * URL文字列(aString)で指定された画像を読み込めなかった時のエラー処理。良好（2013年5月19日）
	 */
	private static void boo(String aString)
	{
		aString = "Error: Not Found\n" + aString;
		JOptionPane.showMessageDialog(null, aString, "Boo!", JOptionPane.PLAIN_MESSAGE);
		throw new RuntimeException(aString);
	}

	/**
	 * MVCのビュー(aView)を指定された寸法(aDimension)でウィンドウに乗せて出す。良好（2013年5月19日）
	 */
	private static void open(View aView, Dimension aDimension)
	{
		JFrame aWindow = new JFrame("Download Image");
		aWindow.getContentPane().add(aView);
		aWindow.setMinimumSize(aDimension);
		aWindow.setMaximumSize(aDimension);
		aWindow.setResizable(false);
		aWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		aWindow.addNotify();
		int titleBarHeight = aWindow.getInsets().top;
		aWindow.setSize(aDimension.width, aDimension.height + titleBarHeight);
		aWindow.setLocation(50, 70);
		aWindow.setVisible(true);
	}
}
